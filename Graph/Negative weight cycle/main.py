#User function Template for python3

class Solution:
	def isNegativeWeightCycle(self, n, edges):
        dist = [10**9]*n
	    dist[0] = 0
	    for j in range(n-1):
    	    for i in range(len(edges)):
    	        u = edges[i][0]
    	        v = edges[i][1]
    	        w = edges[i][2]
    	        
    	        if(dist[u] + w < dist[v]):
    	            dist[v] = dist[u] + w
    	        
    	    
	    
	    
	    for i in range(len(edges)):
            u = edges[i][0]
	        v = edges[i][1]
	        w = edges[i][2]
	        
	        if(dist[u] + w < dist[v]): return 1
	    
	    
	    return 0


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        edges = []
        for _ in range(m):
            edges.append(list(map(int, input().split())))
        obj = Solution()
        ans = obj.isNegativeWeightCycle(n, edges)
        print(ans)

        print("~")

# } Driver Code Ends