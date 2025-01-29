# User function Template for Python3

class Solution:
    def solve(self,x,y):
        if(x >= self.n or x < 0): return 0
        if(y >= self.m): return 0
        
        if(y == m-1):
            return self.mat[x][y]
    
        if(self.dp[x][y] != -1): return self.dp[x][y]
    
        topRight = self.solve(x-1,y+1)
        right = self.solve(x,y+1)
        bottomRight = self.solve(x+1,y+1)
        
        self.dp[x][y] = self.mat[x][y] + max(topRight,right,bottomRight)
        
        return self.dp[x][y]
            
    def maxGold(self, mat):
        
        self.mat = mat
        self.n = len(mat)
        self.m = len(mat[0])
        self.dp = [[-1 for i in range(self.m)] for j in range(self.n)]
        
        
        answer = 0
        
        for i in range(n):
            sol = self.solve(i,0)
            answer = max(answer,sol)
            
        return answer


#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        m = int(input())
        mat = []
        j = 0
        for i in range(n):
            mat.append(list(map(int, input().split())))

        ob = Solution()
        print(ob.maxGold(mat))
        print("~")

# } Driver Code Ends