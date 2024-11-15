#User function Template for python3

class Solution:  
    
    #Function to find the maximum money the thief can get.
    
    def helper(self,arr,n,dp):
        if(n <= 0): return 0
        if(n == 1): return arr[0]
        
        if(dp[n] != -1): return dp[n]
        
        pick = arr[n-1] + self.helper(arr,n-2,dp)
        noPick = self.helper(arr,n-1,dp)
        
        dp[n] = max(pick,noPick)
        
        return dp[n]
    
    def findMaxSum(self,arr):
        n = len(arr)
        dp = [-1 for i in range(len(arr)+1)]
        self.helper(arr,n,dp)
        return dp[n]
        # code here





#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

sys.setrecursionlimit(10**6)
# Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):

        a = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.findMaxSum(a))
        print("~")

# } Driver Code Ends