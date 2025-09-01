#include<bits/stdc++.h>
using namespace std;
void print(vector<int>arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(vector<int>&arr, int n)
{
    for(int i=0;i<n-1; i++)
    {
        bool swapped =0;
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
            swap(arr[j],arr[j+1]);
            swapped=1;
            }
        }
        if(swapped == 0)
        break;
    }
     cout<<"run"<<endl;
     print(arr,n);
}
void insertionsort(vector<int>arr, int n)
{
    for(int i=1; i<n; i++)
    {
        bool swapped=0;
        for(int j=i; j>=1; j--)
        {
            if(arr[j] < arr[j-1])
            {
                swapped=1;
                swap(arr[j], arr[j-1]);
            }
        }
         cout<<"run"<<endl;
        if(swapped == 0) break;
    }
     print(arr,n);
}
void selectionsort(vector<int>&arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(arr[i] > arr[j])
            swap(arr[i], arr[j]);
        }
    }
    print(arr,n);
}

int main () {
    vector<int>arr={781,13,21,224,23,56,122,432,443};
    int n=arr.size();
    
    bubblesort(arr,n);
    // insertionsort(arr,n);
    // selectionsort(arr,n);
}