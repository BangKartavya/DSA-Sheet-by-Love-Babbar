#User function Template for python3

class Solution:
    def divide(self, dividend, divisor):
        sign: int = 1
        
        if((dividend < 0) ^ (divisor < 0)): sign = -1
        
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        quotent: int = 0
        
        for i in range(31,-1,-1):
            if((divisor << i) <= dividend):
                quotent |= (1 << i)
                dividend -= divisor << i
        
        
        return quotent*sign


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        inp = list(map(int, input().split()))

        a = inp[0]
        b = inp[1]

        ob = Solution()

        print(ob.divide(a, b))

        print("~")

# } Driver Code Ends