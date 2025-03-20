#User function Template for python3
import heapq

class Solution:
    def smallestRange(self, KSortedArray, n, k):
        minHeap = []
        
        left = KSortedArray[0][0]
        right = KSortedArray[0][0]

        for i in range(k):
            left = min(left,KSortedArray[i][0])
            right = max(right,KSortedArray[i][0])
            heapq.heappush(minHeap,(KSortedArray[i][0],i,0))
            
        result = [left,right]
        
        while(minHeap):
            val,listNumber,idx = heapq.heappop(minHeap)
            
            idx+=1
            
            if(idx >= n): break
            heapq.heappush(minHeap,(KSortedArray[listNumber][idx],listNumber,idx))
            
            right = max(right,KSortedArray[listNumber][idx])
            left = minHeap[0][0]
            
            if(right-left < result[1] - result[0]):
                result = [left,right]

        return result

#{ 
 # Driver Code Starts
#Initial Template for Python 3

t=int(input())
for _ in range(t):
    line=input().strip().split()
    n=int(line[0])
    k=int(line[1])
    numbers=[]
    for i in range(k):
        numbers.append([int(x) for x in input().strip().split()])
    r = Solution().smallestRange(numbers, n, k)
    print(r[0],r[1])
    print("~")
# } Driver Code Ends