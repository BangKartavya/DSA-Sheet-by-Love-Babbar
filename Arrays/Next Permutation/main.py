#User function Template for python3

class Solution:
    def nextPermutation(self, arr):
        n:int = len(arr)
        ind:int = -1
        
        for i in range(n-2,-1,-1):
            if(arr[i] < arr[i+1]):
                ind = i
                break
        
        if(ind == -1):
            arr.reverse()
            return
        
        for i in range(n-1,-1,-1):
            if(arr[i] > arr[ind]):
                arr[i],arr[ind] = arr[ind],arr[i]
                break
        
        j: int = n-1
        i: int = ind+1
        
        while(i < j):
            arr[i],arr[j] = arr[j],arr[i]
            i+=1
            j-=1
        
        return
        

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        N = len(arr)
        for i in range(N):
            arr[i] = int(arr[i])

        ob = Solution()
        ob.nextPermutation(arr)
        for i in range(N):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends