#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(arr[j+1], arr[j]);
        }
    }
}

int main ()
{
    int n;
    vector<int> arr;
    cout << "Enter Number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    bubbleSort(arr, n);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}