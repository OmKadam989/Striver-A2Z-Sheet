/*
output:
1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 
*/

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n=5;
    
    // print row 
    for(int i=1; i<=n; i++)
    {
        // print column
        for(int j=1; j<=i; j++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}