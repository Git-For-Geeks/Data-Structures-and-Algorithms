class Solution {
public:
    void solve(int i,int &n,vector<int> &tmp,vector<vector<int>> &ans,vector<int> &num)
    {
        ans.push_back(tmp);
        if(i>n)return;
        for(int j = i; j < n; j++){
            tmp.push_back(num[j]);
            solve(j+1,n,tmp,ans,num);
            while(j<n-1&&num[j]==num[j+1])j++;
            tmp.pop_back();
        }
    }    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,tmp,ans,nums);
        return ans;
    }
};