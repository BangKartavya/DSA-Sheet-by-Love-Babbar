

class Solution:
    
    #Function to find the minimum number of swaps required to sort the array.
	def minSwaps(self, arr):
        mp = {}
        temp = arr[:]
        temp.sort()
        
        for i in range(len(arr)):
            mp[arr[i]] = i
        
        ans = 0
        
        for i in range(len(arr)):
            if(arr[i] != temp[i]):
                init = arr[i]
                ans+=1
                
                arr[i],arr[mp[temp[i]]] = arr[mp[temp[i]]],arr[i]
                
                mp[init] = mp[temp[i]]
                mp[temp[i]] = i
        
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.minSwaps(arr)
        print(res)
        t -= 1
# } Driver Code Ends