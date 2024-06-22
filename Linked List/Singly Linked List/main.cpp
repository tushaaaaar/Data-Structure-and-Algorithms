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
        Node* newNode = new Node(val);
        Node* curr = head;
        if (curr == NULL)
        {
            head =  newNode;
            return;
        }
        while (curr->val != after && curr->next != NULL)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);
        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        newNode->next = curr->next;
        curr->next = newNode;
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

    list.insertAfter(5, 4);
    list.insertAfter(2, 5);
    list.insertAfter(3, 1);
    list.display();

    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    
    list.display();
}