class Solution:
    def rowWithMax1s(self, arr):
        ans_ind: int = -1
        
        n: int = len(arr)
        m: int = len(arr[0])
        
        j: int = m-1
        
        for i in range(n):
            while(j>=0 and arr[i][j] == 1):
                ans_ind = i
                j-=1

        return ans_ind


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    idx = 0
    tc = int(data[idx])
    idx += 1

    for _ in range(tc):
        n = int(data[idx])
        m = int(data[idx + 1])
        idx += 2

        arr = []
        for i in range(n):
            arr.append(list(map(int, data[idx:idx + m])))
            idx += m

        ans = Solution().rowWithMax1s(arr)
        print(ans)
        print("~")

# } Driver Code Ends