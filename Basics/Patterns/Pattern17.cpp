/*  
Output:
A A A A A 
B B B B 
C C C 
D D 
E 
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  
   int n=5;
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>=i; j--)
        {
             char c = 'A'+i-1;
            cout<<c<<" ";
          
        }
        cout<<endl;
    }
}