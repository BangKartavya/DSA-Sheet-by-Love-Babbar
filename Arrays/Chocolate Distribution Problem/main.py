#User function Template for python3

class Solution:

    def findMinDiff(self, arr,m):

        n: int = len(arr)
        mini: int = float('inf')
        
        arr.sort()
        
        for i in range(0,n-m+1):
            mini = min(mini,arr[i+m-1]-arr[i])
        
        return mini


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):

        A = [int(x) for x in input().split()]
        M = int(input())

        solObj = Solution()

        print(solObj.findMinDiff(A, M))

# } Driver Code Ends