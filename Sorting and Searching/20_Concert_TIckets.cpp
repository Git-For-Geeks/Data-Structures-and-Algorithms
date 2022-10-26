#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld = long double;
#define pii = pair<int, int>;
#define MAX 1e18

int main() {
	int n,m,temp,max_val;
	cin>>n>>m;
    
    //here, we are using multiset
    //multiset can contain multiple elements with same value
    multiset<ll,greater<int>> tickets;
    
    for(int i=0;i<n;i++){
        cin>>temp;
        //inserting elements in multiset
        tickets.insert(temp);
    }

    for(int i=0;i<m;i++){
        //checking for each customer
        cin>>max_val;

        //Lower bound returns a pointer. If max_val is present
        //in array, it will return an iterator else it will return
        //next greatest element.
        auto it= tickets.lower_bound(max_val);
        if(it==tickets.end())
            cout<<-1<<endl;
        else{
            cout<<*it<<endl;
            tickets.erase(it);
        }
    }

	return 0;
}
