
class Solution:
    def trappingWater(self, arr):
        n: int = len(arr);
        
        pre: list[int] = [0]*n
        suf: list[int] = [0]*n
        
        pre[0] = arr[0]
        suf[n-1] = arr[n-1]

        for i in range(1,n):
            pre[i] = max(pre[i-1],arr[i])
        
        for i in range(n-2,-1,-1):
            suf[i] = max(suf[i+1],arr[i]) 
        ans: int = 0
        
        for i in range(n):
            if(pre[i] > arr[i] and suf[i] > arr[i]): ans+=min(pre[i],suf[i]) - arr[i]
        
        return ans

#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.trappingWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends