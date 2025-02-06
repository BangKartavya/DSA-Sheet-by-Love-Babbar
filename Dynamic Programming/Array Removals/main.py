#User function Template for python3


class Solution:

    def lower_bound(self,x):
        idx = self.n
        
        s = 0
        e = self.n-1
        
        while(s <= e):
            mid = s + (e-s)//2;
            
            if(self.arr[mid] > x):
                idx = min(idx,mid)
                e = mid-1
            else:
                s = mid+1
        
        return idx
        
	def removals(self,arr, n, k):
        arr.sort()
        
        self.arr = arr
        self.n = n
        
        if(arr[n-1] - arr[0] <= k): return 0

        rem = float("inf")
        
        for i in range(n-1):
            x = k + arr[i]
            lb = self.lower_bound(x)
            
            
            rem = min(rem,n-(lb-i))
        
        return rem
#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, k = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.removals(arr, n, k)
        print(ans)
        tc -= 1
        print("~")
# } Driver Code Ends