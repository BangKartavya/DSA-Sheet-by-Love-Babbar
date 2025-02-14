#User function Template for python3

class Solution:
    def solve(self,i,j,isTrue):
        if(i > j): return 0
        
        if(i == j):
            if(isTrue): return int(s[i] == 'T')
            else: return int(s[i] == 'F')
        
        if(self.dp[i][j][int(isTrue)] != -1): return self.dp[i][j][int(isTrue)]
        
        res = 0
        
        for k in range(i+1,j,2):
            leftTrue = self.solve(i,k-1,True)
            leftFalse = self.solve(i,k-1,False)
            rightTrue = self.solve(k+1,j,True)
            rightFalse = self.solve(k+1,j,False)
        
            if(s[k] == '&'):
                if(isTrue):
                    res += (leftTrue * rightTrue)
                else:
                    res += (leftTrue * rightFalse + leftFalse * rightFalse + leftFalse * rightTrue)
        
            elif(s[k] == '|'):
                if(isTrue):
                    res += (leftTrue*rightTrue + leftTrue* rightFalse + leftFalse * rightTrue)
                else:
                    res += (leftFalse * rightFalse)
            
            elif(s[k] == '^'):
                if(isTrue):
                    res += (leftTrue * rightFalse + leftFalse * rightTrue)
                else:
                    res += (leftTrue * rightTrue + leftFalse * rightFalse)
            
            
        self.dp[i][j][int(isTrue)] = res
        return res
            
            
    def countWays(self, s):
        self.s = s
        self.n = len(s)
        self.dp = [[[-1 , -1] for i in range(self.n+1)] for i in range(self.n+1)]
        
        return self.solve(0,self.n-1,True)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input().strip()
        print(Solution().countWays(s))
        print("~")

# } Driver Code Ends