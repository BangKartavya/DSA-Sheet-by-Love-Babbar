
from typing import List


class Solution:
    def solve(self,i,j):
        if(i >= self.n or j >= self.m): return 0
        
        if(self.dp[i][j] != -1): return self.dp[i][j]
        
        right = self.solve(i,j+1)
        down = self.solve(i+1,j)
        diag = self.solve(i+1,j+1)
        
        if(self.mat[i][j] == 1):
            self.dp[i][j] = 1 + min(right,down,diag)
            self.maxi = max(self.maxi,self.dp[i][j])
            return self.dp[i][j]
        
        self.dp[i][j] = 0
        
        return self.dp[i][j]
        
    def maxSquare(self, mat):
        self.mat = mat
        self.n = len(mat)
        self.m = len(mat[0])
        self.dp = [[-1 for i in range(self.m)] for j in range(self.n)]
        self.maxi = 0
        self.solve(0,0)
        
        return self.maxi
        



#{ 
 # Driver Code Starts
class IntMatrix:

    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        m = int(input())
        mat = IntMatrix().Input(n, m)

        obj = Solution()
        res = obj.maxSquare(mat)

        print(res)

        print("~")

# } Driver Code Ends