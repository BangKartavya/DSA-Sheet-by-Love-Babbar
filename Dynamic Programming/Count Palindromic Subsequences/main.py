class Solution:
    
    def solve(self,i,j):
        if(i >= self.n or j < i): return 0
        
        if(i == j): return 1
        
        if(self.dp[i][j] != -1): return self.dp[i][j]
        
        if(self.s[i] == self.s[j]):
            self.dp[i][j] = 1 + self.solve(i+1,j) + self.solve(i,j-1)
            return self.dp[i][j]
            
        self.dp[i][j] = self.solve(i+1,j) + self.solve(i,j-1) - self.solve(i+1,j-1)
    
        return self.dp[i][j]
    
    def countPS(self,s):
        self.s = s
        self.n = len(s)
        
        self.dp = [[-1 for i in range(self.n+1)] for j in range(self.n+1)]
        
        return self.solve(0,self.n-1)



#{ 
 # Driver Code Starts
#Initial template for Python 3

import sys

sys.setrecursionlimit(2000)  # Increase limit as needed

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        ob = Solution()
        print(ob.countPS(input().strip()))

# } Driver Code Ends