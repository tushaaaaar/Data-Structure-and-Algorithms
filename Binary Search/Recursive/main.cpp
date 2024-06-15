#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int>& arr, int l, int r, int x)
{
    if (l <= r)
    {
        int mid = l + (r-l)/2;
        if (x == arr[mid])
            return true;
        else if (x < arr[mid])
            return binary_search(arr, l, mid-1, x);
        else
            return binary_search(arr, mid+1, r, x);
    }
    return false;
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
    if (binary_search(arr, 0, n-1, x))
        cout << "Element Present in Array" << endl;
    else
        cout << "Element is not Present in Array" << endl;
     return 0;
}