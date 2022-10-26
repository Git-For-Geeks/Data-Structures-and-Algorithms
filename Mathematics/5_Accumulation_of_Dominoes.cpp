#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

	ll n, m; cin >> n >> m;
	
	if(m == 1){
		cout << n-1 << endl;
	}
	
	else if(m%2 == 0){
		
		ll ans = m/2;
		ans = ans + (ans-1);
		
		ans = ans * n;
		cout << ans << endl;
		
	}
	
	else{
		
		ll ans = m/2;
		ans += ans;
		
		ans = ans * n;
		cout << ans << endl;
		
	}




return 0;
}
