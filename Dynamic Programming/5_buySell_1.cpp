#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice=INT_MAX; 
            int maxProfit=0; 
            for(int i=0;i<prices.size();i++){
                if(minPrice>prices[i]){
                    minPrice=prices[i]; 
                } 
                else if(prices[i]-minPrice>maxProfit){
                    maxProfit=prices[i]-minPrice; 
                }
            }
            return maxProfit; 
        }
}; 

int main(){
    vector<int> prices = {7,1,5,3,6,4}; 
    Solution ob; 
    cout<<ob.maxProfit(prices)<<endl; 
    return 0;
}