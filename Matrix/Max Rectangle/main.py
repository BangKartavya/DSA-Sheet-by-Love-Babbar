#User function Template for python3


class Solution:
    def largest_area(self,M,m):
        stk: list[int] = []
        
        ans: int = 0
        for i in range(m+1):
            
            while(len(stk) and (i == m or M[stk[len(stk)-1]] >= M[i])):
                height: int = M[stk[len(stk)-1]]
                stk.pop();
                width: int = 0
                if(len(stk) == 0): width = i
                else: width = i-stk[len(stk)-1]-1
                
                ans = max(ans,width*height)
            
            stk.append(i)
        
        return ans
        
    def maxArea(self,M, n, m):
        ans: int = 0
        hist: list[int] = [0]*m
        
        for i in range(n):
            for j in range(m):
                if(M[i][j] == 1): hist[j]+=1
                else: hist[j] = 0
            
            area: int = self.largest_area(hist,m)
            ans = max(ans,area)
        
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver Code 
if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        R,C = map(int, input().strip().split())
        A = []
        for i in range(R):
            line = [int(x) for x in input().strip().split()]
            A.append(line)
        print(Solution().maxArea(A, R, C)) 
        print("~")
	
# This code is contributed 
# by SHUBHAMSINGH10 

# } Driver Code Ends