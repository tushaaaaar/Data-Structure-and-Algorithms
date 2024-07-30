#include <iostream>
using namespace std;

class Node
{
public:
    int coeff;
    int exp;
    Node* next;

    Node (int coeff, int exp) : coeff(coeff), exp(exp), next(NULL) {}
};

class ListNode
{
private:
    Node* head;

public:
    ListNode () : head(NULL) {}

    void polynomial(int coeff, int exp)
    {
        if (coeff == 0)
            return;
        
        Node* poly = new Node(coeff, exp);
        if (head == NULL || head->exp < exp)
        {
            poly->next = head;
            head = poly;
        }
        else
        {
            Node* current = head;
            while (current->next != NULL && current->next->exp >= exp)
            {
                current = current->next;
            }
            poly->next = current->next;
            current->next = poly;
        }
    }

    void display()
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->next == NULL && current->exp != 0)
                cout << current->coeff << "*x^" << current->exp;
            else if (current->exp != 0)
                cout << current->coeff << "*x^" << current->exp << " + ";
            else
                cout << current->coeff;
            current = current->next;
        }
    }
};

int main()
{
    ListNode list;
    int n;
    cout << "Enter degree of polynomial: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int coeff;
        cout << "Enter coefficient of x^" << i << ": ";
        cin >> coeff;
        list.polynomial(coeff, i);
    }
    list.display();
}
