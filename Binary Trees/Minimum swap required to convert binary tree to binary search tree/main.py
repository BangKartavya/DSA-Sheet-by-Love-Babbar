class Solution:
    def inOrder(self,i):
        if(i >= self.n):
            return
        
        self.inOrder(2*i+1)
        self.inOrderArr.append(self.arr[i])
        self.inOrder(2*i+2)
        
    def minSwaps(self, arr):
    
        self.n = len(arr)
        self.arr = arr
        self.inOrderArr = []
        
        self.inOrder(0)
        
        vp = [[self.inOrderArr[i],i] for i in range(self.n)]
        vp.sort()
        visited = [False] * self.n
        swaps = 0
        
        for i in range(self.n):
            
            if( visited[i] or i == vp[i][1]): 
                continue
        
            j = i
            siz = 0
        
            while(not visited[j]):
                visited[j] = True
                j = vp[j][1]
                siz+=1
            
            if(siz > 1):
                swaps += (siz-1)
            else:
                swaps+= siz
                
        
        return swaps
    


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.minSwaps(arr)
        print(ans)
        print("~")
# } Driver Code Ends