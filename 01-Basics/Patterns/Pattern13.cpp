/*
output:

* 
* * 
* * * 
* * * * 
* * * * 
* * * 
* * 
* 

*/

// hiee

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int n=5;
    
   for(int i=1; i<=n; i++)
   {
       for(int j=1; j<i; j++)
       {
           cout<<"*"<<" ";
       }
       cout<<endl;
   }
   for(int i=1; i<n; i++)
   {
       for(int j=n-i; j>=1; j--)
       {
           cout<<"*"<<" ";
       }
       cout<<endl;
   }
}