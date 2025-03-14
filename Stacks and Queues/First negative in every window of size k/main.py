#User function Template for python3
from collections import deque 

class Solution:
    def FirstNegativeInteger(self, arr, k): 
        dq = deque([])
        n = len(arr)
        for i in range(k):
            if(arr[i] < 0):
                dq.append(i)
        
        i = 0
        j = k-1
        
        result = []
        
        while(j < n):
            if(len(dq) == 0): result.append(0)
            else: 
                val = dq.popleft()
                dq.appendleft(val)
                result.append(arr[val])
            
            if(arr[i] < 0):
                dq.popleft()
            i+=1
            j+=1
            
            if(j < n and arr[j] < 0):
                dq.append(j)

        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())

        if k <= 0 or k > len(arr):
            tc -= 1
            continue

        ob = Solution()
        ans = ob.FirstNegativeInteger(arr, k)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends