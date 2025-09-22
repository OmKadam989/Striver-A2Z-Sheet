#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// Brute Force Approach
// 1. Sort the array (O(N logN))
// 2. Smallest is arr[0]
// 3. Scan for first element different from smallest → second smallest
// ------------------------------------------------------------
void bruteforce(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());  // O(N logN)
    int smallest = arr[0];
    int secsmallest = INT_MAX;

    for (int i = 1; i < n; i++)   // O(N)
    {
        if (arr[i] != smallest) {  // ✅ should compare with smallest, not secsmallest
            secsmallest = arr[i];
            break;
        }
    }

    cout << "Brute: " << smallest << " " << secsmallest << endl;
    // Time Complexity: O(N logN + N) ≈ O(N logN)
    // Space Complexity: O(1) (ignoring input array copy in parameter)
}

// ------------------------------------------------------------
// Better Approach (Two Pass)
// 1. Find the smallest in one pass (O(N))
// 2. Find the min element greater than smallest in another pass (O(N))
// ------------------------------------------------------------
void betterapproach(vector<int> arr, int n)
{
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {   // O(N)
        if (arr[i] < smallest) smallest = arr[i];
    }

    int secsmallest = INT_MAX;
    for (int i = 0; i < n; i++) {   // O(N)
        if (arr[i] > smallest && arr[i] < secsmallest) {
            secsmallest = arr[i];
        }
    }

    cout << "Better: " << smallest << " " << secsmallest << endl;
    // Time Complexity: O(N + N) = O(N)
    // Space Complexity: O(1)
}

// ------------------------------------------------------------
// Optimized Approach (Single Pass)
// 1. Keep track of smallest and second smallest while traversing
// ------------------------------------------------------------
void optimizedApproach(vector<int> arr, int n)
{
    int smallest = arr[0];
    int secsmallest = INT_MAX;

    for (int i = 1; i < n; i++)   // O(N)
    {
        if (arr[i] < smallest) {
            secsmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < secsmallest) {
            secsmallest = arr[i];
        }
    }

    cout << "Optimal: " << smallest << " " << secsmallest << endl;
    // Time Complexity: O(N)
    // Space Complexity: O(1)
}

// ------------------------------------------------------------
int main() {
    vector<int> arr = {23, 32, 4, 33, 44};

    bruteforce(arr, arr.size());
    betterapproach(arr, arr.size());
    optimizedApproach(arr, arr.size());

    return 0;
}
