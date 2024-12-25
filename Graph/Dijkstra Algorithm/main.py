# {
# Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys
import heapq
from typing import List, Tuple


# } Driver Code Ends

from heapq import heapify, heappush, heappop


class Solution:
    # Function to find the shortest distance of all the vertices
    # from the source vertex src.
    def dijkstra(self, adj: List[List[Tuple[int, int]]], src: int) -> List[int]:
        pq = []
        heapify(pq)

        n = len(adj)
        ans = [float("inf")] * n

        ans[src] = 0
        heappush(pq, [0, src])

        while len(pq) != 0:
            top = heappop(pq)

            dist = top[0]
            node = top[1]

            for i in adj[node]:
                newDist = dist + i[1]
                newNode = i[0]

                if ans[newNode] > newDist:
                    ans[newNode] = newDist
                    heappush(pq, [newDist, newNode])

        return ans


# {
# Driver Code Starts.

if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        V, E = map(int, input().strip().split())
        adj = [[] for _ in range(V)]
        for _ in range(E):
            u, v, w = map(int, input().strip().split())
            adj[u].append((v, w))
            adj[v].append((u, w))
        src = int(input())
        ob = Solution()

        res = ob.dijkstra(adj, src)
        for i in res:
            print(i, end=" ")
        print()
        print("~")
# } Driver Code Ends
