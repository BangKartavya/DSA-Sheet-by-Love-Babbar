#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

#User function Template for python3

class Solution:
    def heapify(self,arr,n,i):
        largest = i
        
        l = 2 * i + 1
        r = 2 * i + 2
        
        if(l < n and arr[l] > arr[largest]):
            largest = l
        if(r < n and arr[r] > arr[largest]):
            largest = r
        
        if(largest != i):
            arr[i],arr[largest] = arr[largest],arr[i]
            self.heapify(arr,n,largest)
        
    def heapSort(self, arr):
        n = len(arr)
        for i in range(n//2-1,-1,-1):
            self.heapify(arr,n,i)

        for i in range(n-1,0,-1):
            arr[0],arr[i] = arr[i],arr[0]
            
            self.heapify(arr,i,0)

        return

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ob.heapSort(arr)
        print(*arr)
        print("~")
        t -= 1


# } Driver Code Ends