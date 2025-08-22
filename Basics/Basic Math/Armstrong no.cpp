Problem:
Given an integer n, check whether it is an Armstrong number or not.

An Armstrong number (also known as a narcissistic number) is a number that is equal 
to the sum of its own digits each raised to the power of the number of digits.

Note: In this code, we are checking the special case of 3-digit Armstrong numbers, 
where sum of cubes of digits = number itself.

Examples:

Example 1:
Input: n = 153
Output: Yes
Explanation: 1³ + 5³ + 3³ = 153 → Armstrong number.

Example 2:
Input: n = 123
Output: No
Explanation: 1³ + 2³ + 3³ = 36 ≠ 123 → Not an Armstrong number.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is Armstrong
bool isArmstrong(int n) {
    int sum = 0;
    int temp = n; // Keep original number for comparison
    
    while (n) {
        int rem = n % 10;         // Extract last digit
        sum += (rem * rem * rem); // Add cube of digit
        n /= 10;                  // Remove last digit
    }
    
    return (sum == temp); // True if Armstrong number
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    
    while (t--) {
        int n;
        cin >> n;
        
        if (isArmstrong(n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}