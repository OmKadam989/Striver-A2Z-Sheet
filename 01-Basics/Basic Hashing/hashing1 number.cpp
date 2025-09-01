#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "size: ";
    cin >> n;

    int arr[n];
    // Input array elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    // Precomputing frequencies using a hash array
    // Assuming elements are in the range [0, 12]
    int hash[13] = {0};

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++; // count occurrences
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    // Answer each query
    while (q--) {
        int k;
        cin >> k; // element whose frequency we need
        cout << "frequency of " << k << " = " << hash[k] << endl;
    }
}
