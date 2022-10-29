class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        diff = float("inf")
        for i, a in enumerate(nums):
            l, r = i + 1, len(nums) - 1
            while l < r:
                threesum = a + nums[l] + nums[r]
                if abs(target - threesum) < diff:
                    diff = abs(target - threesum)
                    closest = threesum
                if threesum < target:
                    l += 1
                elif threesum > target:
                    r -= 1
                else:
                    return threesum
        return closest
