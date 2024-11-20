class Solution:
    
    #Function to find minimum number of pages.
    def helper(self,arr,n,k,maxPage):
        
        cnt: int = 1
        read: int = 0
        
        for i in range(n):
            if(arr[i] > maxPage):
                return False
            
            if(read + arr[i] > maxPage):
                cnt+=1
                read = arr[i]
                
                if(cnt > k):
                    return False
            
            else:
                read+=arr[i]
        
        return True
    
    def findPages(self, arr, k):
        if(k > len(arr)): return -1
        
        s: int = 0
        e: int = sum(arr)
        ans: int = -1
        while(s<=e):
            mid: int = s + (e-s)//2
            
            if(self.helper(arr,len(arr),k,mid)):
                ans = mid
                e = mid-1
            else:
                s = mid+1
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import bisect
#Main
if __name__ == '__main__':
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.findPages(A, D)
        print(ans)
        print("~")

# } Driver Code Ends