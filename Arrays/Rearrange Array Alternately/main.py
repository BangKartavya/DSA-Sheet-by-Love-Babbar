#User function Template for python3
class Solution:
    ##Complete this function
    #Function to rearrange  the array elements alternately.
    def rearrange(self,arr, n): 
        max_ind: int = n-1
        min_ind: int = 0
        maxi: int = arr[n-1]+1
        
        for i in range(0,n):
            if(i % 2 == 0):
                arr[i] = (arr[max_ind]%maxi)*maxi + arr[i]
                max_ind -= 1
            else:
                arr[i] = (arr[min_ind]%maxi)*maxi + arr[i]
                min_ind += 1
        
        for i in range(0,n):
            arr[i] //= maxi
        
        return
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math




def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            
            ob=Solution()
            ob.rearrange(arr,n)
            
            for i in arr:
                print(i,end=" ")
            
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends