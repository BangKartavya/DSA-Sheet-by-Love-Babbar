from typing import List

class Solution:
    def zeroSumSubmat(self, mat):
        n = len(mat)
        m = len(mat[0])
        maxi = 0
        for i in range(n):
            tempRow = [0]*m
            for j in range(i,n):
                for c in range(m):
                    tempRow[c] += mat[j][c]
            
                mp = {}
                sumi = 0
                
                for c in range(m):
                    sumi += tempRow[c]
                    
                    if(sumi == 0):
                        maxi = max(maxi,(j-i+1)*(c+1))
                
                    if(mp.get(sumi) is not None):
                       maxi = max(maxi,(j-i+1)*(c-mp[sumi]))
                    else:
                        mp[sumi] = c
                
                if(sumi == 0):
                    maxi = max(maxi,(j-i+1)*m)

        return maxi
        



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        r = int(input())
        c = int(input())
        matrix = [[0 for j in range(c)] for i in range(r)]
        for i in range(r):
            t = [int(el) for el in input().split()]
            for j in range(c):
                matrix[i][j] = t[j]
        ans = ob.zeroSumSubmat(matrix)
        print(ans)
        print("~")

# } Driver Code Ends