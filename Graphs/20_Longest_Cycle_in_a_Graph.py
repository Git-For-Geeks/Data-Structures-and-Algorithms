from collections import defaultdict

class Solution(object):
    def longestCycle(self, edges):
        n = len(edges)
        longest= [-1]
        inEdge = [False]*n
        outEdge = [False]*n
        candidate = [False]*n
        visited = [False]*n
        
        for i in range(n):
            if edges[i] > -1:
                outEdge[i] = True
                inEdge[edges[i]] = True
        
        for i in range(n):
            if inEdge[i] and outEdge[i]:
                candidate[i] = True
        
        def dfs(node, step, timesVisited):                
            timesVisited[node] = step
            visited[node] = True
            x = edges[node]
            if x > -1 and candidate[x]:
                if visited[x] and timesVisited[x] > -1:
                    longest[0] = max(longest[0], step-timesVisited[x]+1)
                    return
                if visited[x] == False:
                    dfs(x, step+1, timesVisited)
                
        for i in range(n):
            if visited[i] == False and candidate[i]:
                timesVisited = defaultdict(lambda: -1)
                dfs(i, 0, timesVisited)
        
        return longest[0]