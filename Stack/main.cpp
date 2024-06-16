#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    int SIZE;
    int ptr;
    vector<int> stack;

public:
    Stack(int size) : SIZE(size), ptr(-1), stack(size) {}

    bool isFull()
    {
        return ptr == SIZE - 1;
    }   

    bool isEmpty()
    {
        return ptr == -1;
    }

    void push(int num)
    {
        if (isFull())
        {
            cout << "Stack is Full!" << endl;
            return;
        }
        stack[++ptr] = num;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Element popped: " << stack[ptr--] << endl;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return stack[ptr];
    }
};

int main()
{
    cout << "Enter size of stack: ";
    int size;
    cin >> size;
    Stack st(size);
    int choice;
    while (true)
    {
        cout << "0. Exit\n1. Push\n2. Pop\n3. Top" << endl
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
            st.push(num);
            break;
        }
        case 2:
            cout << "Element popped!" << endl;
            st.pop();
            break;
        case 3:
            cout << "Element on top: " << st.top() << endl;
            break;
        default:
            cout << "Invalid choice! Please choose a valid option." << endl;
            cout << endl;
        }
    }
    return 0;
}
