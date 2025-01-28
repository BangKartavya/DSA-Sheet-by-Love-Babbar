#User function Template for python3

class Solution:
    def solve(self,start,end):
        if(start == end): return 0
        
        if(self.dp[start][end] != -1): return self.dp[start][end]
        
        mini = 10**9
        
        for k in range(start,end):
            mini = min(mini,self.arr[start-1]*self.arr[k]*self.arr[end] + self.solve(start,k) + self.solve(k+1,end))
            
        self.dp[start][end] = mini
        
        return mini
    
    def matrixMultiplication(self, arr):
        n = len(arr)
        self.dp = [[-1 for i in range(n)] for j in range(n)]
        self.arr = arr
        
        return self.solve(1,n-1)
        


#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())  # number of test cases
for _ in range(t):
    arr = list(map(int, input().split()))  # input array
    s = Solution().matrixMultiplication(arr)  # find the missing number
    print(s)  # print the result
    print("~")

# } Driver Code Ends