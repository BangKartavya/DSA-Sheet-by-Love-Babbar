#User function Template for python3

class Solution:
    def countSubArrayProductLessThanK(self, arr, n, k):
        left = 0
        right = 0
        
        prod = 1
        
        cnt = 0
        
        while(right < n):
            prod *= arr[right]
            
            while(left <= right and prod >= k):
                prod //= arr[left]
                left+=1
            
            cnt += (right-left+1)
            right+=1
    
    
        return cnt
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():

    T = int(input())

    while (T > 0):
        n, k = [int(x) for x in input().strip().split()]
        arr = [int(x) for x in input().strip().split()]

        print(Solution().countSubArrayProductLessThanK(arr, n, k))

        T -= 1

        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends