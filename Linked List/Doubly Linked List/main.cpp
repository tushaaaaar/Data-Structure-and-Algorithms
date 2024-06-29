#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) : val(val), next(NULL), prev(NULL) {}
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
        if (head != NULL)
            head->prev = newNode;     
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
        newNode->prev = curr;

        if (curr->next != NULL)
            curr->next->prev = newNode;

        curr->next = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
        newNode->prev = curr;
    }

    void printForward() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printBackward() {
        if (head == NULL) return;
        Node* curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main ()
{
    ListNode list;
    list.insertAtBeginning(5);
    list.insertAtBeginning(4);
    list.insertAtBeginning(3);
    list.printForward();
    list.printBackward();

    list.insertAfter(5, 4);
    list.insertAfter(2, 5);
    list.insertAfter(3, 1);
    list.printForward();
    list.printBackward();
    
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.insertAtEnd(9);
    list.printForward();
    list.printBackward();
}