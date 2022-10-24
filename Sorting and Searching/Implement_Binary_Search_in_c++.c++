// Binary Search

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,s;
    cout<<"Enter number of array elements: ";
    cin>>n;

    int a[n];
    cout<<"Enter array elements."<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];

    cout<<"Enter a number you want to search: ";
    cin>>s;

    int l=0,h=n;

    while(l<=h)
    {
        int mid = (l+h)/2 ;
        if(s==a[mid])
        {
            cout<<s<<" is found at position "<<mid+1<<" and its index is "<<mid;
            break;
        }
        else if(s>a[mid])
        l=mid+1;
        else
        h=mid-1;
    }

    return 0;
}