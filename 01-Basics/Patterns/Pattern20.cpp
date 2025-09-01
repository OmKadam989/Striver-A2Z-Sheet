/*  
Output:
E 
D E 
C D E 
B C D E 
A B C D E 
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  
  int n=5;
  
//   no. of rows
    for(int i=1; i<=n; i++)
    {
    //   print aplhabet
    char c = 'A'+n-i;
    for(int j=1; j<=i; j++)
    {
        cout<<c<<" ";
        c++;
    }

    cout<<endl;
    }
    
}