#User function Template for python3

class Solution:
    def solve(self, i , transactionCount):
        if(i >= self.n or transactionCount == 2*self.k): return 0
        
        if(self.dp[i][transactionCount] != -1): return self.dp[i][transactionCount]
        
        if(transactionCount % 2 == 0):
            self.dp[i][transactionCount] = max(-self.arr[i] + self.solve(i+1,transactionCount+1),self.solve(i+1,transactionCount))

        else:
            self.dp[i][transactionCount] = max(self.arr[i] + self.solve(i+1,transactionCount+1),self.solve(i+1,transactionCount))

        
        return self.dp[i][transactionCount]

    def maxProfit(self, arr, k):
        self.arr = arr
        self.n = len(arr)
        self.k = k
        self.dp = [[-1 for i in range(2*k+1)] for j in range(self.n+1)]
        
        return self.solve(0,0)

#{ 
 # Driver Code Starts
from collections import deque

if __name__ == "__main__":
    tc = int(input())
    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        print(obj.maxProfit(arr, k))
        print("~")
# } Driver Code Ends