
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
 
        vector <int> in; //vector to add the union elements
        for(int i =0; i<n;i++){
            in.push_back(a[i]); // pushing all the elemnets of array 1 first
        }
        
        int f; //flag variable
        
        for(int i =0; i<m;i++){
            f =0; // setting flag to 0
            for(int j =0; j<n; j++){
                if(a[j] == a[i]){ // checking if there are common elements in both the arrays 
                    f = 1; // if common elemnt found set flag to 1
                    break; // break the inner loop
                }
            }
            if(f!=1) // if flag is not 1 then add that element in the vector
                in.push_back(b[i]);
        }
        
        return in.size(); //return the size of the array i.e. the total union elements
    }
};



int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
