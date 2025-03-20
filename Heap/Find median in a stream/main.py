from heapq import heappush, heappop, heapify

class Solution:
    def getMedian(self, arr):
        smallHeap = [] # maxHeap
        largeHeap = [] # minHeap
        
        result = [0] * len(arr)
        
        heapify(smallHeap)
        heapify(largeHeap)
        
        for i in range(len(arr)):
            heappush(smallHeap, -1 * arr[i])
            
            if(smallHeap and largeHeap and -1 * smallHeap[0] > largeHeap[0]):
                heappush(largeHeap,-1 * smallHeap[0])
                heappop(smallHeap)
        
            if(len(smallHeap) > len(largeHeap) + 1):
                heappush(largeHeap,-1 * smallHeap[0])
                heappop(smallHeap)
            if(len(largeHeap) > len(smallHeap) + 1):
                heappush(smallHeap,-1 * largeHeap[0])
                heappop(largeHeap)
                
            
            if(i % 2 != 0):
                result[i] = (-1 * smallHeap[0] + largeHeap[0])/2
            else:
                if(len(smallHeap) > len(largeHeap)):
                    result[i] = -1 * smallHeap[0]
                else:
                    result[i] = largeHeap[0]
        
        return result

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input().strip())
    for _ in range(t):
        s = input().strip()
        nums = list(map(int, s.split()))
        ob = Solution()
        ans = ob.getMedian(nums)
        print(" ".join(f"{x:.1f}" for x in ans))


if __name__ == "__main__":
    main()

# } Driver Code Ends