#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    int SIZE;
    int f, r;
    vector<int> queue;

public:
    Queue(int size) : SIZE(size), f(0), r(0), queue(size) {}

    bool isFull()
    {
        return (r+1) % SIZE == f;
    }

    bool isEmpty()
    {
        return r == f;
    }

    void enqueue(int num)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
            return;
        }
        r = (r+1) % SIZE;
        queue[r] = num;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        f =  (f+1) % SIZE;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return queue[(f+1) % SIZE];
    }
};

int main()
{
    cout << "Enter size of queue: ";
    int size;
    cin >> size;
    Queue q(size+1);
    int choice;
    while (true)
    {
        cout << "0. Exit\n1. Enqueue\n2. Dequeue\n3. Front" << endl
             << "Choose: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
        {
            cout << "Enter data: ";
            int num;
            cin >> num;
            q.enqueue(num);
            break;
        }
        case 2:
            cout << "Element dequeued!" << endl;
            q.dequeue();
            break;
        case 3:
            cout << "Element at front: " << q.front() << endl;
            break;
        default:
            cout << "Invalid choice! Please choose a valid option." << endl;
            cout << endl;
        }
    }
    return 0;
}