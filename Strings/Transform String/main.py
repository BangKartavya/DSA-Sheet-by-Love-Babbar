#Back-end complete function Template for Python 3

class Solution:
    def transform(self, A, B): 
        freq = [0]*256
        
        n = len(A)
        m = len(B)
        
        if(n!=m): return -1
        
        for i in range(n):
            freq[ord(A[i])]+=1
            freq[ord(B[i])]-=1
        
        for i in range(256):
            if(freq[i] != 0): return -1
        
        cnt = 0
        i = n-1
        j = m-1
        
        while(i >= 0):
            if(A[i] == B[j]):
                i-=1
                j-=1
            else:
                cnt+=1
                i-=1
                
        
        return cnt

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        A = line[0]
        B = line[1]
        ob = Solution()
        print(ob.transform(A,B))
        print("~")
# } Driver Code Ends