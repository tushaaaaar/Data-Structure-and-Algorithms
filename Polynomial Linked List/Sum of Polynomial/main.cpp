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

    void addPolynomial(ListNode list1, ListNode list2)
    {
        Node* p1 = list1.head;
        Node* p2 = list2.head;

        while (p1 != NULL && p2 != NULL)
        {
            if (p1->exp == p2->exp)
            {
                int sumCoeff = p1->coeff + p2->coeff;
                if (sumCoeff != 0)
                    polynomial(sumCoeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->exp > p2->exp)
            {
                polynomial(p1->coeff, p1->exp);
                p1 = p1->next;
            }
            else
            {
                polynomial(p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }
        while (p1 != NULL)
        {
            polynomial(p1->coeff, p1->exp);
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            polynomial(p2->coeff, p2->exp);
            p2 = p2->next;
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
        cout << endl;
    }
};

int main()
{
    ListNode list1, list2, list3;
    int n, m;
    cout << "Enter degree of first polynomial: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int coeff;
        cout << "Enter coefficient of x^" << i << ": ";
        cin >> coeff;
        list1.polynomial(coeff, i);
    }
    list1.display();

    cout << "Enter degree of second polynomial: ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int coeff;
        cout << "Enter coefficient of x^" << i << ": ";
        cin >> coeff;
        list2.polynomial(coeff, i);
    }
    list2.display();

    cout << "Sum of the two polynomial: ";
    list3.addPolynomial(list1, list2);
    list3.display();
}
