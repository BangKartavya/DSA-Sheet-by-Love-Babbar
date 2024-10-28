#User function Template for python3

class Solution:
       
    def smallThan(self,matrix,x):
        cnt: int = 0
        for i in matrix:
            low: int = 0
            high: int = len(i)-1
            
            ans: int = len(i)
            
            while(low <= high):
                mid: int = (low + high)//2
                if(i[mid] > x): 
                    ans = mid
                    high = mid-1
                else:
                    low = mid+1
            
            cnt += ans
        
        return cnt
        
    def median(self, matrix, n, m):
        low:int = float('inf')
        high:int = float('-inf')
        
        for i in range(n):
            low = min(low,matrix[i][0])
            high = max(high,matrix[i][m-1])
        
        
        while(low <= high):
            mid:int = (low + high)//2
            
            smal: int = self.smallThan(matrix,mid)
            
            if(smal <= n*m//2): low = mid+1
            else: high = mid-1
        
        return low


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        r,c = map(int,input().strip().split())
        matrix = [[0 for j in range(c)] for i in range(r)]
        for i in range(r):
            t=[int(el) for el in input().split()]
            for j in range(c):
                matrix[i][j]=t[j]
        ans = ob.median(matrix, r, c);
        print(ans)
        print("~")
# } Driver Code Ends