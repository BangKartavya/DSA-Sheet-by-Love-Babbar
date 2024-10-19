class Solution:
	def mergeOverlap(self, arr):
        arr.sort()
        
        n = len(arr)
        
        ans = []
        ans.append(arr[0])

        for i in range(1,n):
            if(arr[i][0] <= ans[-1][1]):
                ans[-1][1] = max(ans[-1][1],arr[i][1])
            
            else:
                ans.append(arr[i])
        
        return ans;

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        a = list(map(int, input().strip().split()))
        arr = []
        j = 0
        for i in range(n):
            x = a[j]
            j += 1
            y = a[j]
            j += 1
            arr.append([x, y])
        obj = Solution()
        ans = obj.mergeOverlap(arr)
        for i in ans:
            for j in i:
                print(j, end=" ")
        print()

# } Driver Code Ends