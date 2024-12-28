
class Solution:

    def kosaraju(self, adj):
        n = len(adj)
        vis = [False]*n
        sorted_finishing_time = []

        def dfs(node,adj):
            vis[node] = True
            
            for i in adj[node]:
                if(not vis[i]):
                    dfs(i,adj)
            
            sorted_finishing_time.append(node)

        for i in range(n):
            if(not vis[i]):
                dfs(i,adj)
        
        rev_adj = []
        
        for i in range(n):
            rev_adj.append([])
        
        for i in range(n):
            vis[i] = False
            for j in adj[i]:
                rev_adj[j].append(i)

        cnt = 0

        while len(sorted_finishing_time) > 0:
            i = sorted_finishing_time.pop()
            
            if(not vis[i]):
                dfs(i,rev_adj)
                cnt+=1
        
        return cnt


#{ 
 # Driver Code Starts
from collections import OrderedDict
import sys

sys.setrecursionlimit(10**6)
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V = int(input())
        E = int(input())
        adj = [[] for i in range(V)]
        for i in range(E):
            a, b = map(int, input().strip().split())
            adj[a].append(b)
        ob = Solution()

        print(ob.kosaraju(adj))

#Back end complete function Template for Python

# } Driver Code Ends