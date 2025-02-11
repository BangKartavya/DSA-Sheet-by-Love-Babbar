#User function Template for python3
class Solution:
    # Function to find the maximum length of alternating subsequence
    def alternatingMaxLength(self, arr):
        n = len(arr)
        
        up = 1
        down = 1
        
        for i in range(n-1):
            if(arr[i] > arr[i+1]):
                up = down + 1
            elif(arr[i] < arr[i+1]):
                down = up + 1
        
        return max(up,down)


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    tc = int(data[0])
    for i in range(1, tc + 1):
        s = data[i].strip().split()
        nums = list(map(int, s))
        obj = Solution()
        ans = obj.alternatingMaxLength(nums)
        print(ans)
        print("~")
# } Driver Code Ends