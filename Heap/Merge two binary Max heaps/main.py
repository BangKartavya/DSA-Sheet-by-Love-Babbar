#User function Template for python3

class Solution():
    def maxHeapify(self,merged,n,i):
        l = 2 * i + 1
        r = 2 * i + 2
        maxi = i
        
        if(l < n and merged[l] > merged[maxi]):
            maxi = l
        if(r < n and merged[r] > merged[maxi]):
            maxi = r
        
        
        if(maxi != i):
            merged[maxi],merged[i] = merged[i],merged[maxi]
            self.maxHeapify(merged,n,maxi)
        
    def buildMaxHeap(self,merged,n):
        
        for i in range(n//2-1,-1,-1):
            self.maxHeapify(merged,n,i)
        
    def mergeHeaps(self, a, b, n, m):
        merged = []
        
        for i in a:
            merged.append(i)
        for j in b:
            merged.append(j)
        
        self.buildMaxHeap(merged,n+m)

        return merged

#{ 
 # Driver Code Starts
#Initial Template for Python 3

def isMerged(arr1, arr2, merged):
    if (len(arr1) + len(arr2) != len(merged)):
        return False
    arr1 += arr2
    arr1.sort()
    mergedCopy = sorted(merged)
    if (arr1 != mergedCopy):
        return False
    for i in range(1, len(merged)):
        if merged[i] > merged[(i-1)//2]:
            return False

    return True

if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int, input().split())
        a = [int(i) for i in input().split()]
        b = [int(i) for i in input().split()]
        copyA = a[:]
        copyB = b[:]
        obj = Solution()
        merged = obj.mergeHeaps(a, b, n, m)
        flag = isMerged(copyA, copyB, merged)
        print(0 if flag == False else 1)

        print("~")
# } Driver Code Ends