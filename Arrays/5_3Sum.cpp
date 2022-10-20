/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> ans; 
            int n=nums.size(); 
            sort(nums.begin(),nums.end()); 
            for(int i=0;i<n-2;i++){ 
                if(i>0 and nums[i]==nums[i-1]){
                    continue; 
                }
                int s=i+1, e=n-1; 
                while(s<e){
                    if(nums[i]+nums[s]+nums[e]==0){
                        ans.push_back({nums[i],nums[s],nums[e]});
                        while(s<e and nums[s]==nums[s+1]){
                            s++; 
                        }
                        while(s<e and nums[e]==nums[e-1]){
                            e--; 
                        } 
                        s++; 
                        e--; 
                    } 
                    else{
                        nums[i]+nums[s]+nums[e]<0 ? s++ : e--;
                    }
                }
            }
            return ans; 
        }
};
// @lc code=end

