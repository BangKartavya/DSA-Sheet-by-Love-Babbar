#User function Template for python3

class Solution:
    def max_pow_2(self,n):
        cnt = 0
        
        while((1 << cnt) <= n): cnt+=1
    
        return cnt - 1
        
    #Function to return sum of count of set bits in the integers from 1 to n.
    def countSetBits(self,n):
        
        if(n == 0): return 0
        
        if(n == 1): return 1
        
        x = self.max_pow_2(n)
        y = x * (1 << (x-1))
        z = n - (1 << x)
        
        return y+z+1+self.countSetBits(z)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        ob=Solution()
        print(ob.countSetBits(int(input())))
        print("~")
# } Driver Code Ends