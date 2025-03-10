#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends


class Solution:
    def getMaxArea(self,arr):
        stk = []
        n = len(arr)
        maxi = 0
        for i in range(n):
            while(len(stk) != 0 and arr[i] < arr[stk[-1]]):
                elem = stk[-1]
                stk.pop()
                nextSmaller = i
                prevSmaller = 0
                
                if(len(stk) == 0): prevSmaller = -1
                else: prevSmaller = stk[-1]
                
                maxi = max(maxi,arr[elem] * (nextSmaller - prevSmaller -1))

            stk.append(i)
        
        while(len(stk) != 0):
            elem = stk[-1]
            stk.pop()
            nextSmaller = n
            prevSmaller = 0
            
            if(len(stk) == 0): prevSmaller = -1
            else: prevSmaller = stk[-1]
            
            maxi = max(maxi,arr[elem] * (nextSmaller - prevSmaller - 1))

        return maxi            

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.getMaxArea(arr)
        print(res)
        print("~")
        t -= 1


# } Driver Code Ends