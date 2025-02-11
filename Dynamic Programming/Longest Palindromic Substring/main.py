#User function Template for python3

class Solution:
    def longestPalindrome(self, s):
        maxi = 0
        startIdx = -1
        n = len(s)
        
        for i in range(n):
            st = i
            e = i
            
            while(st >= 0 and e < n and s[st] == s[e]):
                if(e-st+1 > maxi):
                    maxi = e-st+1
                    startIdx = st
                
                st-=1
                e+=1
        
        for i in range(n):
            st = i
            e = i+1
            
            while(st >= 0 and e < n and s[st] == s[e]):
                if(e-st+1 > maxi):
                    maxi = e-st+1
                    startIdx = st
                
                st-=1
                e+=1
        
        return s[startIdx:startIdx+maxi]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        S = input().strip()
        ob = Solution()
        print(ob.longestPalindrome(S))
        print("~")

# } Driver Code Ends