class Solution:
    def insert(self,stk, element):
        if(len(stk) == 0 or stk[-1] < element):
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

    def Sorted(self, s):
        self.reverse(s)



#{ 
 # Driver Code Starts

if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.Sorted(arr)
        for e in range(len(arr)):
            print(arr.pop(), end=" ")
        print()


        print("~")
# } Driver Code Ends