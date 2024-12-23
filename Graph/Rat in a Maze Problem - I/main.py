#User function Template for python3
class Solution:
    def solve(self,x,y,mat,ans,res,n):
        if(x < 0 or x >= n or y < 0 or y >= n):
            return
        
        if(x == n-1 and y == n-1):
            res.append(ans)
            return
        mat[x][y] = 0
        
        if(x-1 >= 0 and mat[x-1][y] != 0): self.solve(x-1,y,mat,ans+"U",res,n)
        if(x+1 < n and mat[x+1][y] != 0): self.solve(x+1,y,mat,ans+"D",res,n)
        if(y-1 >= 0 and mat[x][y-1] != 0): self.solve(x,y-1,mat,ans+"L",res,n)
        if(y+1 < n and mat[x][y+1] != 0): self.solve(x,y+1,mat,ans+"R",res,n)
        mat[x][y] = 1
        return
    
    # Function to find all possible paths
    def findPath(self, mat):
        n = len(mat)
        
        if(mat[0][0] == 0 or mat[n-1][n-1] == 0): return []
        
        res = []
        
        self.solve(0,0,mat,"",res,n)
        res.sort()
        return res




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        input_line = input().strip()
        mat = eval(input_line)

        solution = Solution()
        result = solution.findPath(mat)

        if not result:
            print("[]")
        else:
            print(" ".join(result))
        print("~")

# } Driver Code Ends