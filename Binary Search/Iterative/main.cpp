#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int>& arr, int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        if (x == arr[mid]) return true;
        else if (x < arr[mid]) r = mid - 1;
        else l = mid + 1;
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
    if (binarySearch(arr, 0, n-1, x))
        cout << "Element Present in Array" << endl;
    else
        cout << "Element is not Present in Array" << endl;
     return 0;
}