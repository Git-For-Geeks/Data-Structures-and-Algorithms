// Problem Link: https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1 

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

class Solution{
    public: 
        ll toh(int N,int from, int to,int helper){
            if(N==0){
                return 0; 
            }
            toh(N-1,from,helper,to); 
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl; 
            toh(N-1,helper,to,from); 
            return pow(2,N)-1; 
        }
};

int main(){
    int N=3; 
    Solution obj;
    cout<<obj.toh(N,1,3,2); 
    return 0;
}