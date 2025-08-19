/*
output:
    * 
   * * 
  * * * 
 * * * * 
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
    //   print space
    for(int j=1; j<=n-i; j++)
    {
        cout<<" ";
    }
    // print star
    for(int j=1; j<=i; j++)
    {
        cout<<"*"<<" ";
    }
    cout<<endl;
   }
}