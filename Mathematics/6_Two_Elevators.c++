#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int a,b,c,e1,e2;
        cin>>a>>b>>c;

        if(b<c)
        e2=2*c-b-1;
        else
        e2=b-1;

        e1=a-1;

        if(e1<e2)
        cout<<"1\n";
        else if(e1>e2)
        cout<<"2\n";
        else
        cout<<"3\n";
    }

    return 0;
}