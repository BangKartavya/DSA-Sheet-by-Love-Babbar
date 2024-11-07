#User function Template for python3
class Solution:
    def minimumNumberOfSwaps(self,S):
        opened = 0
        closed = 0
        unbal = 0
        ans = 0
        
        for i in range(len(S)):
            if(S[i] == '['):
                opened+=1
                ans += unbal
                
                if(unbal > 0): unbal -= 1
            
            else:
                closed+=1
                if(closed > opened): 
                    unbal = closed-opened
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        
        S=str(input())
        ob = Solution()
        print(ob.minimumNumberOfSwaps(S))
        print("~")
# } Driver Code Ends