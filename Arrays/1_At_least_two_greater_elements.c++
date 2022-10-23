// Problem link --> https://practice.geeksforgeeks.org/problems/at-least-two-greater-elements4625/1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    int num;
    char end = ' ';
    cin>>noskipws;
    while(end!='\n')
    {
        cin>>num;
        a.push_back(num);
        cin>>end;
    }

    int n=a.size();

    sort(a.begin(),a.end());

    for(auto i=0;i<n-2;i++)
    cout<<a[i]<<" ";

    return 0;
}