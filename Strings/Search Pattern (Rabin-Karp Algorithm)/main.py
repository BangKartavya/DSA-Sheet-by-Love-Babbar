#User function Template for python3

class Solution:
    def search(self, pattern, text):
        n: int = len(text)
        m: int = len(pattern)
        
        ans: list[int] = []
        
        for i in range(n-m+1):
            j: int = 0
            while(j < m and pattern[j] == text[i+j]): j+=1

            if(j == m): ans.append(i+1)
        
        return ans
        


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input().strip()
        patt = input().strip()
        ob = Solution()
        ans = ob.search(patt, s)
        for value in ans:
            print(value,end = ' ')
        print()
        print("~")
# } Driver Code Ends