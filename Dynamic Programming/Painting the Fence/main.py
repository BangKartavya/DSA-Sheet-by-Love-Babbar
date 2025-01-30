#User function Template for python3

class Solution:
    def solve(self,i,k):
        if(i == 1): return k
        if(i == 2): return k*k
        
        if(self.dp[i][k] != -1): return self.dp[i][k]
        
        same = (k-1) * self.solve(i-1,k)
        diff = (k-1) * self.solve(i-2,k)
        
        self.dp[i][k] = same + diff
        
        return same + diff
        
    def countWays(self,n,k):
        self.dp = [[-1 for i in range(k+1)] for j in range(n+1)]
        
        return self.solve(n,k)



#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    k = int(input())
    ob = Solution()
    ans = ob.countWays(n, k)
    print(ans)

    print("~")

# } Driver Code Ends