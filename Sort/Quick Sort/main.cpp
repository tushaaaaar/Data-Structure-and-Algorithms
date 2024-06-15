#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right)
{
    int pivot = arr[left];
    int l = left;
    int r = right;
    while (l < r)
    {
        while (arr[l] <= pivot)
            l++;
        while (arr[r] > pivot)
            r--;
        if (l < r)
            swap(arr[l], arr[r]);
    }
    swap(arr[r], arr[left]);
    return r;
}

void quickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
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
    quickSort(arr, 0, n-1);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}