class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        
        def calc_distance(p1, p2):
            return abs(p2[0]- p1[0]) + abs(p2[1] - p1[1])
        
        def find(i):
            temp = i
            while temp !=  parents[temp]:
                parents[temp] = parents[parents[temp]]
                temp = parents[temp]
            return temp
        
        def union(a, b):
            pa, pb = find(a), find(b)
            
            if pa == pb:
                return 0
            
            if rank[pa] > rank[pb]:
                largerp, smallerp = pa, pb
            else:
                largerp, smallerp = pb, pa
            
            rank[largerp] += rank[smallerp]
            parents[smallerp] = largerp
            return 1
        
       
        n = len(points)
        parents = list(range(n))
        rank = [1] * n
        
        edges = sorted(((calc_distance(points[i], points[j]), (i,j))
                       for i in range(len(points) - 1)
                        for j in range(i + 1, len(points))),
                        reverse=True)
        
        total =  0 
        while n > 1:
            cost, edge = edges.pop()
            if union(edge[0], edge[1]):
                total += cost
                n -= 1
        return total
