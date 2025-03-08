#User function Template for python3

from typing import List

class Solution:
    def insert(self,stk, element):
        if(len(stk) == 0):
            stk.append(element)
            return
        
        top = stk[-1]
        stk.pop()
        self.insert(stk,element)
        stk.append(top)
        
    
    def reverse(self,St): 
        if(len(St) == 0):
            return
        
        top = St[-1]
        St.pop()
        self.reverse(St)
        self.insert(St,top)


#{ 
 # Driver Code Starts

#Initial Template for Python 3

 
for _ in range(int(input())):
    N = int(input())
    St = list(map(int, input().split()))
    ob = Solution()
    ob.reverse(St)
    print(*St)
    print("~")
# } Driver Code Ends