// Problem Link: https://leetcode.com/problems/sort-colors/  

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void sortColors(vector<int> &nums){
            int low=0,mid=0,high=nums.size()-1; 
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[low],nums[mid]); 
                    low++; mid++;
                }
                else if(nums[mid]==1){
                    mid++; 
                }
                else{
                    swap(nums[mid],nums[high]); 
                    high--; 
                }
            }
        }
};

int main(){
    // vector<int> v={2,0,1,1,2,0,0,2,1}; 
    vector<int> v={2,0,2,1,1,0}; 
    Solution obj; 
    obj.sortColors(v); 
    for(auto x:v){
        cout<<x<<" "; 
    }
    return 0;
}