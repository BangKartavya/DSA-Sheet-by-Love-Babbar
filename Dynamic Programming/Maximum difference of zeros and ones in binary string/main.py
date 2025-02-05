#User function Template for python3
class Solution:
	def maxSubstring(self, S):
		n = len(S)
		
		maxi = float("-inf")
		currSum = 0
		
		for i in range(n):
		    x = -1
		    if(S[i] == '0'): x = 1
		    
		    currSum += x
		    if(currSum > maxi): maxi = currSum
		    
		    if(currSum < 0): currSum = 0

        return maxi


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.maxSubstring(s)
        print(answer)
        print("~")

# } Driver Code Ends