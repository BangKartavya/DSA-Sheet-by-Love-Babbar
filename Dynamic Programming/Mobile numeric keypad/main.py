#User function Template for python3
class Solution:
	def solve(self, i, n):
	    if(n == 1): return 1

        if(self.dp[i][n] != -1): return self.dp[i][n]
	    
	    res = 0

	    for it in self.mp[i]:
	        res += self.solve(it,n-1)
	    self.dp[i][n] = res
	    
	    return res
	    
	def getCount(self, n):
	    self.mp = {}
	    self.mp[0] = [0,8]
	    self.mp[1] = [1,2,4]
	    self.mp[2] = [2,1,3,5]
	    self.mp[3] = [3,2,6]
	    self.mp[4] = [4,1,7,5]
	    self.mp[5] = [5,4,2,6,8]
	    self.mp[6] = [6,3,5,9]
	    self.mp[7] = [7,4,8]
	    self.mp[8] = [8,5,7,9,0]
	    self.mp[9] = [9,6,8]
	    self.dp = [[-1 for i in range(n+1)] for j in range(10)]
	    ans = 0
	    
	    for i in range(10):
	        ans += self.solve(i,n)
	        
        return ans
	    

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.getCount(n)
        print(ans)

        print("~")
# } Driver Code Ends