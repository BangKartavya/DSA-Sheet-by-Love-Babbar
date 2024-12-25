class Solution:
    def dfs(self,i,adj,vis,stk):
        vis[i] = True
        for j in adj[i]:
            if(not vis[j]):
                self.dfs(j,adj,vis,stk)
        
        stk.append(i)
    #Function to return list containing vertices in Topological order.
    def topologicalSort(self,adj):
        n = len(adj)
        stk = []
        vis = [False]*n
        
        for i in range(n):
            if(not vis[i]):
                self.dfs(i,adj,vis,stk)
                
        return stk[::-1]



#{ 
 # Driver Code Starts
# Driver Program

import sys

sys.setrecursionlimit(10**6)


def check(graph, N, res):
    if N != len(res):
        return False
    map = [0] * N
    for i in range(N):
        map[res[i]] = i
    for i in range(N):
        for v in graph[i]:
            if map[i] > map[v]:
                return False
    return True


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        N = int(input())
        e = int(input())
        adj = [[] for i in range(N)]

        for i in range(e):
            u, v = map(int, input().split())
            adj[u].append(v)

        ob = Solution()

        res = ob.topologicalSort(adj)

        if check(adj, N, res):
            print(1)
        else:
            print(0)
        print("~")
# Contributed By: Harshit Sidhwa

# } Driver Code Endsm