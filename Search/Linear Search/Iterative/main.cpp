#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(vector<int>& arr, int x)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return true;
    }
    return false;
}

int main()
{
    int n, x;
    vector <int> arr;
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
    if (linearSearch(arr, x))
        cout << "Element Present in Array" << endl;
    else
        cout << "Element is not Present in Array" << endl;
     return 0;
}