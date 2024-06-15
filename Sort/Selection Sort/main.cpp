#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
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
    selectionSort(arr, n);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}