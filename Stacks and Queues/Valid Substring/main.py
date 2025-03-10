#User function Template for python3

class Solution:
    def findMaxLen(self, S):
        op = 0
        cl = 0
        maxi = 0
        n = len(S)
        
        for i in range(n):
            if(S[i] == '('): op+=1
            else: cl+=1
            
            if(op == cl):
                maxi = max(maxi,2 * op)
            
            elif(cl > op):
                cl = 0
                op = 0
        op = 0
        cl = 0
        for i in range(n-1,-1,-1):
            if(S[i] == '('): cl+=1
            else: op+=1
            
            if(op == cl):
                maxi = max(maxi,2 * op)
            
            elif(cl > op):
                cl = 0
                op = 0

        
        return maxi
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.findMaxLen(S))
        print("~")

# } Driver Code Ends