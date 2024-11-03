#User function Template for python3

class Solution:
	def lps(self, s):
        
        n = len(s)
        
        lps = [0]*n
        
        lps[0] = 0
        i = 0
        j = 1
        
        while(j < n):
            if(s[i] == s[j]):
                lps[j] = i+1
                i+=1
                j+=1
            else:
                if(i == 0):
                    lps[j] = 0
                    j+=1
                else:
                    i = lps[i-1]
        
        return lps[n-1]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.lps(s)
        print(answer)

# } Driver Code Ends