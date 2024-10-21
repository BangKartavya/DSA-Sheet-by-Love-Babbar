class Solution:
    #User function Template for python3
    
    # arr[]: Input Array
    # N : Size of the Array arr[]
    #Function to count inversions in the array.
    def __init__(self):
        self.cnt = [0]
    def merge(self,arr,left,mid,right):
        low:int = left
        high:int = mid+1
        temp = []
        while(low <= mid and high <= right):
            if(arr[low] <= arr[high]):
                temp.append(arr[low])
                low+=1
            else:
                temp.append(arr[high])
                self.cnt[0] += (mid-low+1)
                high+=1
        
        while(low <= mid):
            temp.append(arr[low])
            low+=1
        while(high <= right):
            temp.append(arr[high])
            high+=1
        
        for i in range(left,right+1):
            arr[i] = temp[i-left]
    
    def mergeSort(self,arr,left,right):
        if(left < right):
            mid:int = (left+right)//2
            self.mergeSort(arr,left,mid)
            self.mergeSort(arr,mid+1,right)
            self.merge(arr,left,mid,right)
    
    def inversionCount(self, arr):
        self.mergeSort(arr,0,len(arr)-1);
        return self.cnt[0];


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
        obj = Solution()
        print(obj.inversionCount(a))

# } Driver Code Ends