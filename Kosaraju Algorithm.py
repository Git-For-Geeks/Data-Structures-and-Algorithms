
class Solution:
    
    
    def kosaraju(self, V, adj):
        # code here
        visit=set()
        s=[]
        l=0
        def dfssort(e):
            visit.add(e)
            for i in dic[e]:
                if i not in visit:
                    dfssort(i)
            s.append(e)
        def dffk(e):
            visited.add(e)
            for i in dic2[e]:
                if i not in visited:
                    dffk(i)
            
        
        dic={i:[] for i in range(V)}
        
        for i in range(len(adj)):
            for j in range(len(adj[i])):
                dic[i].append(adj[i][j])
        for i in range(V):
            if i not in visit:
                dfssort(i)
        dic2={i:[] for i in range(V)}
        
        for i in range(len(adj)):
            for j in range(len(adj[i])):
                dic2[adj[i][j]].append(i)

        
        visited=set()
        maxi=0
        for i in s[::-1]:
            if i not in visited:
                dffk(i)
                l=l+1
                
        

        
        
        return l
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import OrderedDict 
import sys 

sys.setrecursionlimit(10**6) 
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
        ob = Solution()
        
        print(ob.kosaraju(V, adj))
# } Driver Code Ends
