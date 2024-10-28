#User function Template for python3

class Solution:
    def MedianOfArrays(self, array1, array2):
        n: int = len(array1)
        m: int = len(array2)
        total: int = n+m
        
        if(n > m): return self.MedianOfArrays(array2,array1)
        
        low: int = 0
        high: int = n
        left: int = (total+1)//2
        
        while(low <= high):
            mid1: int = low + (high-low)//2
            mid2: int = left - mid1
            
            l1: int = -1_000_000_000
            l2: int = -1_000_000_000
            r1: int = 1_000_000_000
            r2: int = 1_000_000_000

            if(mid1 < n): r1 = array1[mid1]
            if(mid2 < m): r2 = array2[mid2]
            
            if(mid1 -1 >=0): l1 = array1[mid1-1]
            if(mid2 - 1 >= 0): l2 = array2[mid2-1]
            
            if(l1 > r2): high = mid1-1
            elif(l2 > r1): low = mid1 + 1
            else:
                if(total%2): return max(l1,l2)
                else:
                    if((max(l1,l2)+min(r1,r2))%2): return (max(l1,l2)+min(r1,r2))/2
                    else: return (max(l1,l2)+min(r1,r2))//2

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    tcs=int(input())

    for _ in range(tcs):
        m = input()
        arr1=[int(x) for x in input().split()]
        n = input()
        arr2=[int(x) for x in input().split()]
        
        
        ob = Solution()
        print(ob.MedianOfArrays(arr1,arr2))

# } Driver Code Ends