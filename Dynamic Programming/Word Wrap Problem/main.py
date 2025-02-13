#User function Template for python3

class Solution:
    def solve(self, i, rem):
        if(i >= self.n): return 0
        
        if(self.dp[i][rem+1] != -1): return self.dp[i][rem+1]
        
        if(self.arr[i] > rem):
            self.dp[i][rem+1] = (rem + 1) * (rem + 1) + self.solve(i+1,self.k-self.arr[i]-1)
        else:
            place = self.solve(i+1,rem-arr[i]-1)
            noPlace = (rem + 1) * (rem + 1) + self.solve(i+1,self.k-self.arr[i]-1)
            self.dp[i][rem+1] = min(place,noPlace)
        
        return self.dp[i][rem+1]

	def solveWordWrap(self, arr, k):
        self.arr = arr
        self.n = len(arr)
        self.k = k
        self.dp = [[-1 for i in range(k+2)] for i in range(self.n+1)]
        
        return self.solve(0,k)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        # n = int(input())
        arr = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        ans = obj.solveWordWrap(arr, k)
        print(ans)
        print("~")

# } Driver Code Ends