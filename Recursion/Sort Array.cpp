#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int low = left;
    int high = mid + 1;

    // Merge the two halves
    while (low <= mid && high <= right) {
        if (arr[low] < arr[high]) {
            temp.push_back(arr[low]);
            low++;
        } else {
            temp.push_back(arr[high]);
            high++;
        }
    }

    // Copy the remaining elements from the left half, if any
    while (low <= mid) {
        temp.push_back(arr[low]);
        low++;
    }

    // Copy the remaining elements from the right half, if any
    while (high <= right) {
        temp.push_back(arr[high]);
        high++;
    }

    // Copy the sorted elements back to the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Recursively sort the left half
    mergeSort(arr, left, mid);

    // Recursively sort the right half
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {5, 2, 7, 1, 0, 9};
    int left = 0;
    int right = arr.size() - 1;

    mergeSort(arr, left, right);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
