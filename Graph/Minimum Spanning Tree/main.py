#User function Template for python3
from typing import List
from heapq import heapify, heappush, heappop
class Solution:
    
    #Function to find sum of weights of edges of the Minimum Spanning Tree.
    def spanningTree(self, V: int, adj: List[List[int]]) -> int:
        pq = []
        heapify(pq)
        
        vis = [False]* V
        
        s = 0
        
        heappush(pq,[0,0])
        
        while(len(pq) != 0):
            top = heappop(pq)
            
            weight = top[0]
            node = top[1]
            
            if(vis[node]): continue
            
            vis[node] = True
            s += weight
            
            for i in adj[node]:
                if(not vis[i[0]]):
                    heappush(pq,[i[1],i[0]])
        
        return s


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys
from typing import List

# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        V = int(input())
        E = int(input())
        adj = [[] for i in range(V)]
        for i in range(E):
            u, v, w = map(int, input().strip().split())
            adj[u].append([v, w])
            adj[v].append([u, w])
        ob = Solution()

        print(ob.spanningTree(V, adj))
        print("~")

# } Driver Code Ends