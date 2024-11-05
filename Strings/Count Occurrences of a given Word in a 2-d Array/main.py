#User function Template for python3
class Solution:
    def __init__(self):
        self.ans = 0
        
    def dfs(self,mat,i,j,idx,target):
        if(i < 0 or j < 0 or i == len(mat) or j == len(mat[0]) or idx >= len(target) or target[idx] != mat[i][j]):
            return
    
        if(idx == len(target)-1):
            self.ans+=1
            return
        temp = mat[i][j]
        mat[i][j] = '0'
        self.dfs(mat,i+1,j,idx+1,target)
        self.dfs(mat,i,j+1,idx+1,target)
        self.dfs(mat,i-1,j,idx+1,target)
        self.dfs(mat,i,j-1,idx+1,target)
        mat[i][j] = temp
        
        
    def findOccurrence(self,mat,target):
        n = len(mat)
        m = len(mat[0])
        
        for i in range(n):
            for j in range(m):
                self.dfs(mat,i,j,0,target)

        return self.ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t=int(input())
    for _ in range(t):
        line=input().strip().split()
        R=int(line[0])
        C=int(line[1])
        mat=[]
        for _ in range(R):
            mat.append( [x for x in input().strip().split()] )
        target=input()
        obj = Solution()
        print(obj.findOccurrence(mat,target))
        print("~")
# } Driver Code Ends