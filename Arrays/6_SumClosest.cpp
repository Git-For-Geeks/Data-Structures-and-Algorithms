class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{

    int mn=INT_MAX,ans;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                if(abs(nums[i]+nums[j]+nums[k]-target)<mn)
                {
                    mn=abs(nums[i]+nums[j]+nums[k]-target);
                    ans= nums[i]+nums[j]+nums[k];
                }
            }
        }
    }
		return ans;

	}
};