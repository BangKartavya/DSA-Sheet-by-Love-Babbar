#User function Template for python3

class Solution:
    def solve(self,n):
        if(n == 1): return 1
        if(n == 2): return 2
        if(n == 3): return 4
        
        if(self.dp[n] != -1): return self.dp[n]
        
        self.dp[n] = self.solve(n-1) + (n-1) * self.solve(n-2)
        
        return self.dp[n]
        
    def countFriendsPairings(self, n):
        self.dp = [-1] * (n+1)
        
        return self.solve(n)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        ob = Solution()
        print(ob.countFriendsPairings(n))
        print("~")

# } Driver Code Ends