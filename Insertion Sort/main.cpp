#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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
    insertionSort(arr, n);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}