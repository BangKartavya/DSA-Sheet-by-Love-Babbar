 #User function Template for python3
 
class Solution:
    
    # arr[] : the input array
    
    #Function to return length of longest subsequence of consecutive integers.
    def findLongestConseqSubseq(self,arr):
        s: set = set()
        maxi: int = 0
        for i in arr:
            s.add(i)
        
        for i in arr:
            key: int = i
            leng: int = 1
            while(key+1 in s):
                leng+=1
                key+=1
            maxi = max(maxi,leng)
        
        return maxi
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        print(Solution().findLongestConseqSubseq(a))

# } Driver Code Ends