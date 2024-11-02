class Solution:
    def __init__(self):
    	self.dp = []
	def func(self,s1,s2,i,j):
	    
	    if(i < 0): 
	        return j+1
	    if(j < 0): 
	        return i+1
	    
	    if(self.dp[i][j] != -1):
	        return self.dp[i][j];
	    
	    if(s1[i]==s2[j]): 
	        self.dp[i][j] = self.func(s1,s2,i-1,j-1)
	        return self.dp[i][j]
	        
	    else:
	        deletion = 1 + self.func(s1,s2,i-1,j)
	        insertion= 1 + self.func(s1,s2,i,j-1)
	        replacement = 1 + self.func(s1,s2,i-1,j-1)
	        self.dp[i][j] = min(deletion,min(insertion,replacement))
	        return self.dp[i][j]
	
	def editDistance(self, s1, s2):
	    for i in range(len(s1)):
	        temp = []
	        for j in range(len(s2)):
                temp.append(-1)
            self.dp.append(temp)
		ans = self.func(s1,s2,len(s1)-1,len(s2)-1)
        return ans

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s, t = input().split()
        ob = Solution()
        ans = ob.editDistance(s, t)
        print(ans)

# } Driver Code Ends