#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
using namespace std;

// Do sorted parts ko merge karne wala function
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1); // Temporary array
    int i = left, j = mid + 1, k = 0;

    // Dono halves ko compare karke sorted merge karo
    while (i <= mid && j <= right)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];

    // Agar left half mein kuch bacha ho
    while (i <= mid)
        temp[k++] = arr[i++];

    // Agar right half mein kuch bacha ho
    while (j <= right)
        temp[k++] = arr[j++];

    // Temp array ke elements original array mein copy karo
    for (int l = 0; l < temp.size(); ++l)
        arr[left + l] = temp[l];
}

// Recursive merge sort with multithreading 
void mergeSort(vector<int>& arr, int left, int right, int depth = 0) {
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    // Agar depth kam hai to threads bana ke parallel sort karo
    if (depth < 2) {
        thread t1(mergeSort, ref(arr), left, mid, depth + 1);
        thread t2(mergeSort, ref(arr), mid + 1, right, depth + 1);
        t1.join();
        t2.join();
    } else {
        // Nahi to normal recursive call karo
        mergeSort(arr, left, mid, depth + 1);
        mergeSort(arr, mid + 1, right, depth + 1);
    }

    // Dono halves ko merge karo
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Array before sorting:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    // Multithreaded merge sort call karo
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array:\n";
    for (int num : arr)
        cout << num << " ";
    cout << "\n";

    return 0;
}
