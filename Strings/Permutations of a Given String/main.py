#User function Template for python3

class Solution:
    def solve(self,s,ds,us,freq):
        if(len(s) == len(ds)):
            us.add(ds)
            return
    
        for i in range(len(s)):
            if(not freq[i]):
                freq[i] = True
                ds += s[i]
                self.solve(s,ds,us,freq)
                ds = ds[:-1]
                freq[i] = False
        
    def find_permutation(self, s):
        
        n: int = len(s)
        ds: str = ""
        us: set = set()
        freq: list[bool] = [False]*n
        
        self.solve(s,ds,us,freq)
        ans: list[str] = []
        
        for i in us: ans.append(i)
        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.find_permutation(S)
        ans.sort()
        for i in ans:
            print(i, end=" ")
        print()
        print("~")

# } Driver Code Ends