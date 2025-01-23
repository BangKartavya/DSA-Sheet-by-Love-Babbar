class Solution:
    def checkMirrorTree(self, n, e, A, B):
        mp = {}
        
        for i in range(0,2*e,2):
            try:
                mp[A[i]].append(A[i+1])
            except KeyError:
                mp[A[i]] = [A[i+1]]
                
        
        for i in range(0,2*e,2):
            if(mp[B[i]][-1] != B[i+1]): return 0
            
            mp[B[i]].pop()
        
        return 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n,e=map(int,input().split())
        
        A=list(map(int,input().split()))
        B=list(map(int,input().split()))
        
        ob = Solution()
        print(ob.checkMirrorTree(n,e,A,B))
        print("~")
# } Driver Code Ends