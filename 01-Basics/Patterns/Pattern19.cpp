/*  
Output:
    A    
   ABC   
  ABCDC  
 ABCDEDC 
ABCDEFEDC
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
  
  int n=5;
  
//   no. of rows
    for(int i=1; i<=n; i++)
    {
        // print space
        for(int j=1; j<= n-i; j++)
        {
            cout<<" ";
        }
        // print alphabet
            char c = 'A';
        for(int j=1; j<= (2*i)-1; j++)
        {
        
            cout<<c;
            if( j <= i) c++;
            else c--;
        }
        // print space
        for(int j=1; j<= n-i; j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
    
}