# For leetcode
# My submission https://leetcode.com/submissions/detail/827433145/
# Please copy paste below code to check for leet code
# class Solution:
#     def buildArray(self, target: List[int], n: int) -> List[str]:
#           res = []
#           s = set(target)
#           for i in range(1, target[-1] + 1):
#                 res.append("Push")
#                 if i not in s:
#                     res.append("Pop")
#           return res


n=int(input())
target=list(map(int,input().split()))
res = []
s = set(target)
for i in range(1, target[-1] + 1):
         res.append("Push")
         if i not in s:
                res.append("Pop")
print(res)
