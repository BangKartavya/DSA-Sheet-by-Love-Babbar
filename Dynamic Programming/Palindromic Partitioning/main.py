#User function Template for python3

class Solution:
    def isPal(self,i, j):
        while(i < j):
            if(self.s[i] != self.s[j]):
                return False
            
            i+=1
            j-=1
        
        return True
        
    def solve(self, i):
        if(i >= self.n): return 0
        
        if(self.dp[i] != -1): return self.dp[i]
        
        res = float("inf")
        
        for k in range(i,self.n):
            if(self.isPal(i,k)):
                res = min(res, 1 + self.solve(k+1))
        
        self.dp[i] = res
        return res
        
    def palindromicPartition(self, s):
        self.s = s
        self.n = len(s)
        self.dp = [-1] * (self.n+1)
        
        return self.solve(0) - 1
        
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        string = input()

        ob = Solution()
        print(ob.palindromicPartition(string))

# } Driver Code Ends