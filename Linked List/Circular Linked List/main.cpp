#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* next;

    Node (int val) : val(val), next(NULL) {} 
};

class ListNode
{
private:
    Node* head;

public:
    ListNode () : head(NULL) {}    

    void insertAtBeginning (int val)
    {
        Node* newNode = new Node(val);
        if (head == NULL)
        {
            newNode->next = newNode;
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != head)
                current = current->next;
            
            newNode->next = head;
            current->next = newNode;
            head = newNode;
        }
    }

    void insertAfter(int val, int after) {
        Node* current = head;
        do
        {
            if (current->val == after)
            {
                Node* newNode = new Node(val);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != head)
            current = current->next;
        
        current->next = newNode;
        newNode->next = head;
    }

    void display() {
        Node* current = head;
        do {
            cout << current->val << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};



int main ()
{
    ListNode list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    list.insertAfter(4, 2);

    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);

    list.display();
}