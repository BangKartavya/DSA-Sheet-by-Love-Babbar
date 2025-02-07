#User function Template for python3

class Solution:
    def solve(self,n,i):
        if(n < 0 or i == 3): return 0
        if(n == 0): return 1
        
        if(self.dp[n][i] != -1): return self.dp[n][i]
        
        take = self.solve(n-self.points[i],i)
        noTake = self.solve(n,i+1)
        
        self.dp[n][i] = take + noTake
        return self.dp[n][i]
        
    def count(self, n: int) -> int:
        self.points = [3,5,10]
        self.dp = []
        
        for i in range(n+1):
            temp = []
            for j in range(3):
                temp.append(-1)
            self.dp.append(temp)
            
        
        return self.solve(n,0)
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        ob = Solution()
        print(ob.count(n))
        
        print("~")
# } Driver Code Ends