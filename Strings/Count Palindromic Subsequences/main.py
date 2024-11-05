MOD = 1000000007
class Solution:
    # Your task is to complete this function
    # Function should return an integer
    def counting(self,s,i,j,dp):
        if(i > j): 
            return 0
        if(i == j): 
            return 1
        if(dp[i][j] != -1): 
            return dp[i][j];
        
        
        if(s[i]==s[j]): 
            forward = self.counting(s,i+1,j,dp)%MOD
            backward = self.counting(s,i,j-1,dp)%MOD
            dp[i][j] = (1 + forward + backward)%MOD
        else:
            forward = self.counting(s,i+1,j,dp)%MOD
            backward = self.counting(s,i,j-1,dp)%MOD
            overlap = self.counting(s,i+1,j-1,dp)%MOD
            dp[i][j] = (forward + backward - overlap + MOD)%MOD
        return dp[i][j]
    
    def countPS(self,s):
        
        dp = []
        n = len(s)
        for i in range(n):
            temp = []
            for j in range(n):
                temp.append(-1)
            
            dp.append(temp)
        
        return self.counting(s,0,n-1,dp)%MOD



#{ 
 # Driver Code Starts
#Initial template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        ob=Solution()
        print(ob.countPS(input().strip()))

        print("~")
# } Driver Code Ends