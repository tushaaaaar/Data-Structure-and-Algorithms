#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(NULL) {}
};

class ListNode
{
private:
    Node* head;

public:
    ListNode() : head(NULL) {}

    void insertAtBeginning(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(int val, int after)
    {

    }

    void insertAtEnd(int val)
    {

    }

    void reverse()
    {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display()
    {
        Node* curr = head;
        while (curr != NULL)
        {
            cout << curr -> val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    ListNode list;
    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.display();

    list.reverse();
    list.display();
}