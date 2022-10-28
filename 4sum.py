class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = set()
        nums.sort()
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                k,l = j+1,len(nums)-1
                while k<l:
                    s = nums[i]+nums[j]+nums[k]+nums[l]
                    if s == target:
                        ans.add((nums[i],nums[j],nums[k],nums[l]))
                        l-=1
                        k+=1
                    elif s > target:
                        l-=1
                    else:
                        k+=1
                  
        return ans
