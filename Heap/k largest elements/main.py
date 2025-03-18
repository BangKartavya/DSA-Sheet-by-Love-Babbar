from heapq import heapify, heappush, heappop

class Solution:
	def kLargest(self, arr, k):
		pq = []
		heapify(pq)
		result = []
		n = len(arr)
		
		
		for i in range(k):
		    heappush(pq,arr[i])
		    
		for i in range(k,n):
		    top = heappop(pq)
		    if(top < arr[i]):
		        heappush(pq,arr[i])
		    else:
		        heappush(pq,top)

        while(len(pq) != 0):
            result.append(heappop(pq))
        
        result.reverse()
        
        return result
		


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        ans = ob.kLargest(arr, k)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends