from typing import List
from collections import deque

class Solution:
    def detect(self,src: int,adj,vis):
        n: int = len(adj)
        q = deque()
        q.append([src,-1])
        
        vis[src] = 1
        
        while(q):
            top: list = q.popleft()
            node: int = top[0]
            parent: int = top[1]
            
            for x in adj[node]:
                if(not vis[x]):
                    vis[x] = 1
                    q.append([x,node])
                elif parent != x:
                    return True
    
        return False
        
                
        
    #Function to detect cycle in an undirected graph.
	def isCycle(self, V: int, adj: List[List[int]]) -> bool:
        vis: list[int] = [False]*V
        
        for i in range(V):
            if(not vis[i]):
                if(self.detect(i,adj,vis)):
                    return True
        
        return False
    


#{ 
 # Driver Code Starts
if __name__ == '__main__':

    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
        obj = Solution()
        ans = obj.isCycle(V, adj)
        if (ans):
            print("1")
        else:
            print("0")
        print("~")

# } Driver Code Ends