#User function Template for python3

class Solution:
    def getMinDiff(self, arr,k):
        n = len(arr)
        
        arr.sort()
        
        mini = arr[0]
        maxi = arr[n-1]
        
        ans = maxi - mini
        
        mi = mini + k
        ma = maxi - k
        
        for i in range(0,n-1):
            smallest = min(mi,arr[i+1]-k)
            largest = max(ma,arr[i]+k)
            
            if(smallest < 0): continue
        
            ans = min(ans,largest-smallest)
        
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, k)
        print(ans)
        tc -= 1

# } Driver Code Ends