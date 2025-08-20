/*  
Output:
*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  
  int n=5;
  
    // print upward diagram
    for(int i=1; i<=n; i++)
    {
        // print star
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        // print space
        for(int j=1; j<= 2 *(n-i); j++)
        {
            cout<<" ";
        }
        // print star
         for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    // print downward diagram
    for(int i=1; i<=n; i++)
    {
        // print star
        for(int j=1; j<=n-i; j++)
        {
            cout<<"*";
        }
        // print space
        for(int j=1; j<= 2*(i); j++)
        {
            cout<<" ";
        }
        // print star
        for(int j=1; j<=n-i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    
}