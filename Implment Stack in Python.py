a=list(map(int,input().split()))
n=int(input())
res = []
s = set(a)
for i in range(1, a[-1] + 1):
        res.append("Push")
        if i not in s:
            res.append("Pop")
print(res)