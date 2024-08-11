#include <iostream>
#include <vector>
using namespace std;

void maxHeap(vector<int>& nums, int n, int i) {
    int l = 2*i+1;
    int r = 2*i+2;
    int max = i;
    if (l < n && nums[l] > nums[max])
        max = l;
    if (r < n && nums[r] > nums[max])
        max = r;
    if (i != max) {
        swap(nums[i], nums[max]);
        maxHeap(nums, n, max);
    }
}

void heapSort(vector<int>& nums, int n) {
    for (int i = n/2; i >= 0; i--) {
        maxHeap(nums, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(nums[i], nums[0]);
        maxHeap(nums, i, 0);
    }
}

void display(vector<int>& nums, int n) {
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main () {
    int n;
    vector<int> nums;
    cout << "Enter Number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    heapSort(nums, n);
    display(nums, n);
}
