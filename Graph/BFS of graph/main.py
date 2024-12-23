#User function Template for python3
from collections import deque
class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, adj):
        n: int = len(adj)
        ans: list[int] = []
        
        q: list[int] = deque()
        
        vis: list[bool] = [False]*n
        q.append(0)
        
        while(q):
            top: int = q.popleft()
            
            if(not vis[top]):
                ans.append(top)
                vis[top] = True
                for x in adj[top]:
                    q.append(x)
        

        return ans


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())  # Number of test cases
    for i in range(T):
        V = int(input())  # Number of vertices
        E = int(input())  # Number of edges
        adj = [[] for i in range(V)]  # Adjacency list
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)  # Undirected graph

        ob = Solution()
        ans = ob.bfsOfGraph(adj)
        print(" ".join(map(str, ans)))  # Print the BFS traversal result

# } Driver Code Ends