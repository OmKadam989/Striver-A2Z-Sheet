/*
output:
* * * * * 
* * * * * 
* * * * * 
* * * * * 
* * * * * 
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
        for(int j=1; j<=n; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}