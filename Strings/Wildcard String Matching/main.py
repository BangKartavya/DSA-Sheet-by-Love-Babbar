#User function Template for python3

class Solution:
    def match(self, wild, pattern):
        if(len(wild) == 0 and len(pattern) == 0):
            return True
        print(wild)
        print(pattern)
        if(wild[0] == '*'):
            j = 0
            while(j < len(wild)-1 and wild[j+1] == '*'):
                j+=1
            wild = wild[j:]
        
        if(wild[0] == '*' and len(wild) > 1 and len(pattern) == 0): 
            return False

        if(len(pattern) != 0 and (wild[0] == '?' or wild[0] == pattern[0])):
            return self.match(wild[1:],pattern[1:])
        
        if(len(pattern) == 0): return True
        if(wild[0] == '*'):
            return (self.match(wild,pattern[1:]) or self.match(wild[1:],pattern))
        
        return False




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        wild = input()
        pattern = input()
        
        ob = Solution()
        if(ob.match(wild, pattern)):
            print("Yes")
        else:
            print("No")
        print("~")
# } Driver Code Ends