#include <iostream>
#include <vector>
using namespace std;

void countSort (vector <int>& arr, int n) {
    int maxi = 0;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, arr[i]);
    
    vector <int> brr(maxi+1, 0);
    for (int i = 0; i < n; i++)
        brr[arr[i]]++;

    for (int i = 1; i <= maxi; i++)
        brr[i] += brr[i-1];
    
    vector <int> crr(n);
    for (int i = n-1; i >= 0; i--)
        crr[--brr[arr[i]]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = crr[i];
}

int main () {
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
    countSort(arr, n);
    for (auto a: arr)
        cout << a << " ";
    return 0;
}