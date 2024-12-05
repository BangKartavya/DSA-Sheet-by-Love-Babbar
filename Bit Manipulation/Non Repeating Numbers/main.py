#User function Template for python3

class Solution:
	def singleNumber(self, arr):
        x: int = 0
        
        for i in arr: x ^= i
        
        ans: list[int] = [0,0]
        
        x &= -x
        
        for i in arr:
            if(i&x == 0): ans[0]^=i
            else: ans[1]^= i
            
        
        if(ans[0] > ans[1]): ans[0],ans[1] = ans[1],ans[0]
        
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.singleNumber(arr)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends