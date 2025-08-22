/*
output:
     *
    ***
   *****
  *******
 *********
***********
 *********
  *******
   *****
    ***
     *
*/

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n=5;
    
    // print 5 row up traingle
    {
    //   print space
    for(int i=0; i<=n; i++)
    {
    // print space
    for(int j=1; j<=n-i; j++)
    {
        cout<<" ";
    }
    // print star
    for(int j=1; j<=2*i+1; j++)
    {
        cout<<"*";
    }
    
    cout<<endl;
   }
}
   for(int i=0; i<=n; i++)
   {
    //   print space
    for(int j=0; j<=i; j++)
    {
        cout<<" ";
    }
    // print star
    for(int j=1; j<=(2*n)-(2*i+1); j++)
    {
        cout<<"*";
    }
    
    cout<<endl;
   }
}