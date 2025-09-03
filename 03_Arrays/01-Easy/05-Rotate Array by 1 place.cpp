// Brute Force Approach - Rotate Array by K Steps
// Time Complexity: O(n * k)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

// Function to rotate array to the right by 1 step
void rotateRightByOne(int arr[], int n) {
    if (n <= 1) return;

    int last = arr[n - 1];  // store last element
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];  // shift elements right
    }
    arr[0] = last;  // place last element at front
}

// Function to rotate array to the right by k steps (brute force)
void rotateRightByK(int arr[], int n, int k) {
    k = k % n;  // normalize k
    for (int i = 0; i < k; i++) {
        rotateRightByOne(arr, n);  // do k times
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    rotateRightByK(arr, n, k);

    cout << "Array after rotating by " << k << " steps: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
