#User function Template for python3

class Solution:

    def lookandsay(self, n):
        if(n==1): return "1"
        
        prev: str = self.lookandsay(n-1)
        sz: int = len(prev)
        ans: str = ''
        cnt: int = 0
        
        for i in range(sz):
            cnt+=1
            if(i == sz-1 or prev[i] != prev[i+1]):
                ans += str(cnt) + prev[i]
                cnt=0
        
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        n = int(input())

        solObj = Solution()

        print(solObj.lookandsay(n))

        print("~")
# } Driver Code Ends