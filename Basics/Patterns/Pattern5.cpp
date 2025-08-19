/*
output:
* * * * * 
* * * * 
* * * 
* * 
* 
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
        for(int j=n; j>=i; j--)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

/*
output:
* * * * * 
* * * * 
* * * 
* * 
* 
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
        for(int j=1; j<=n-i+1; j++)
        {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
}

