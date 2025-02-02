#User function Template for python3

class Solution:
    def wordBreak(self, n, s, d):
        if(len(s) == 0): return 1
        
        for i in range(0,len(s)+1):
            pref: str = s[0:i]
            
            if(pref in d and self.wordBreak(n,s[i:],d)): return 1
        
        return 0


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_case = int(input())

    for _ in range(test_case):
        n = int(input())
        dictionary = [word for word in input().strip().split()]
        s = input().strip()
        ob = Solution()
        res = ob.wordBreak(n, s, dictionary)
        if res:
            print(1)
        else:
            print(0)

# } Driver Code Ends