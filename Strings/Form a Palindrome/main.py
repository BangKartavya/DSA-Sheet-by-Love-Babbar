#User function Template for python3

class Solution:
    def __init__(self):
        self.dp = []
        
            
    def lcs(self,s1,s2,n,m):
        if(n==0 or m ==0):
            return 0
        
        if(self.dp[n][m] != -1): return self.dp[n][m]
        
        if(s1[n-1] == s2[m-1]):
            self.dp[n][m] = 1 + self.lcs(s1,s2,n-1,m-1)
        
        else:
            self.dp[n][m] = max(self.lcs(s1,s2,n-1,m),self.lcs(s1,s2,n,m-1))
        
        return self.dp[n][m]
    
    def countMin(self, s):
        n = len(s)
        for i in range(n+1):
            temp = []
            for j in range(n+1):
                temp.append(-1)
                
            self.dp.append(temp)
        s2 = s[::-1]
        
        return n - self.lcs(s,s2,n,n);


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        Str = input()

        solObj = Solution()

        print(solObj.countMin(Str))
        print("~")

# } Driver Code Ends