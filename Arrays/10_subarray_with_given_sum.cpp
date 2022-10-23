// Problem Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public: 
        vector<int> subarraySum(int arr[],int n,ll s){
            int i=0,j=0;          //declaring 2 pointers 
            vector<int> ans={-1};   
            if(s<1)                
                return ans; 
            int curr=0; 
            while(j<=n){
                if(curr==s){
                    ans={i+1,j};       //if we get given sum update array with starting index and ending index 
                    break;
                }
                else if(curr<s){
                    curr+=arr[j];       //if curr sum is less than req. sum add and increment end pointer 
                    j++; 
                }
                else{
                    curr-=arr[i];       //if curr sum is more than req. sum subtract and increment front pointer 
                    i++; 
                }
            } 
            return ans;
        }
};

int main(){
    int N=5,S=12; 
    int arr[N]={1,2,3,7,5}; 
    Solution obj;
    vector<int> res; 
    res=obj.subarraySum(arr,N,S);  
    for(auto i:res)
        cout<<i<<" "; 
    return 0;
}