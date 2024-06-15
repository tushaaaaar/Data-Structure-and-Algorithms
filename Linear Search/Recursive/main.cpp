#include <iostream>
#include <vector>
using namespace std;

bool linear_search(vector<int>& arr, int n, int x)
{
    if (n == 0)
        return false;
    else if (arr[n-1] == x)
        return true;
    return linear_search(arr, n-1, x);
}

int main ()
{
    int n, x;
    vector<int> arr;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    cout << "Enter element you want to search: ";
    cin >> x;
    if (linear_search(arr, n, x))
        cout << "Element Present in Array" << endl;
    else
        cout << "Element is not Present in Array" << endl;
     return 0;
}