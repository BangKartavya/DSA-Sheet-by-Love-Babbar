#User function Template for python3

class Solution:
        
    def minSwap (self,arr, n, k) : 
        fav: int = 0
        non_fav: int = 0
        
        for i in arr:
            if(i <= k): fav+=1
        
        for i in range(fav):
            if(arr[i] > k): non_fav += 1
        
        l: int = 0
        r: int = fav-1
        
        res: int = 1_000_000_000
        
        while(r<n):
            res = min(res,non_fav)
            r+=1
            if(r < n and arr[r] > k): non_fav+=1
            if(l < n and arr[l] > k): non_fav-=1
            l+=1
        
        if(res == 1_000_000_000): return 0
        
        return res;




#{ 
 # Driver Code Starts
#Initial Template for Python 3

for _ in range(0,int(input())):
    n = int(input())
    arr = list(map(int, input().strip().split()))
    k = int(input())
    ob=Solution()
    ans = ob.minSwap(arr, n, k)
    print(ans)
    





# } Driver Code Ends