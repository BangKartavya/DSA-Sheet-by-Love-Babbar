#User function Template for python3

class Solution:
    def solve(self,i,j):
        if(i >= self.n or j < i): return 0
        
        if(i == j): return self.freq[i]
        
        if(self.dp[i][j] != -1): return self.dp[i][j]
        
        res = float("inf")
        prefi = 0
        if(i > 0): 
            prefi = self.pref[i-1]
        
        sumi = self.pref[j] - prefi
        
        for k in range(i,j+1):
            leftSubTree = self.solve(i,k-1)
            rightSubTree = self.solve(k+1,j)
            
            res = min(res,leftSubTree + rightSubTree + sumi)
        
        
        self.dp[i][j] = res
        return self.dp[i][j]
        
    def optimalSearchTree(self, keys, freq, n):
        self.keys = keys
        self.freq = freq
        self.n = n
        self.pref = [0] * n
        self.dp = [[-1 for i in range(self.n+1)] for j in range(self.n+1)]
        self.pref[0] = freq[0]
        
        for i in range(1,n):
            self.pref[i] = freq[i] + self.pref[i-1]
        
        
        return self.solve(0,self.n-1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        n = int(input())
        keys = input().split()
        for itr in range(n):
            keys[itr] = int(keys[itr])
        freq = input().split()
        for itr in range(n):
            freq[itr] = int(freq[itr])
        ob = Solution()
        print(ob.optimalSearchTree(keys, freq, n))
        print("~")
# } Driver Code Ends