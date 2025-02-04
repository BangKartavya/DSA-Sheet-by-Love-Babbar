#User function Template for python3

class Solution:
    def solve(self,eggs,floors):
        if(eggs == 1): return floors
        if(floors <= 1): return floors
        
        if(self.dp[eggs][floors] != -1): return self.dp[eggs][floors]
        
        mini = float("inf")
        
        
        for k in range(1,floors+1):
            mini = min(mini,1 + max(self.solve(eggs-1,k-1),self.solve(eggs,floors-k)))
        
        self.dp[eggs][floors] = mini
        
        return self.dp[eggs][floors]
        
    def eggDrop(self,n, k):
        if(n==1): return k
        if(k<=1): return k
        
        self.dp = [[-1 for i in range(k+1)] for j in range(n+1)]
        
        return self.solve(n,k)


#{ 
 # Driver Code Starts
# Initial Template for Python 3
import atexit
import io
import sys

# Contributed by : gokul

if __name__ == '__main__':
    test_cases = int(input().strip())
    for cases in range(test_cases):
        # Reading the number of eggs from a separate line
        n = int(input().strip())

        # Reading the number of floors from a separate line
        k = int(input().strip())

        # Creating an instance of Solution and calling eggDrop method
        ob = Solution()
        print(ob.eggDrop(n, k))
        print("~")

# } Driver Code Ends