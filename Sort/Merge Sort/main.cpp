#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int k = left;
    vector<int> brr(right-left+1);
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            brr[k - left] = arr[i];
            i++;
        }
        else
        {
            brr[k - left] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        brr[k - left] = arr[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        brr[k - left] = arr[j];
        j++;
        k++;
    }
    for (int i = left; i <= right; i++)
        arr[i] = brr[i - left];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n-1);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}