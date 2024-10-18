#User function Template for python3
class Solution:
	def minJumps(self, arr):
        n = len(arr)
        maxReach = 0
        lastIdx = 0
        jumps = 0
        
        for i in range(n):
            maxReach = max(maxReach,arr[i]+i)
            if(maxReach == i and lastIdx == i and arr[i] == 0):
                return -1
            
            if(lastIdx == i):
                jumps+=1
                lastIdx = maxReach
            
            if(lastIdx >= n-1):
                return jumps
        
        return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        # n = int(input())
        Arr = [int(x) for x in input().split()]
        ob = Solution()
        ans = ob.minJumps(Arr)
        print(ans)

# } Driver Code Ends