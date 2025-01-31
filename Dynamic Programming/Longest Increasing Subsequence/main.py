# User function Template for python3


class Solution:
    def solve(self, i, lastIdx):
        if i >= self.n:
            return 0

        if self.dp[i][lastIdx + 1] != -1:
            return self.dp[i][lastIdx + 1]

        take = 0

        if lastIdx == -1 or self.arr[i] > self.arr[lastIdx]:
            take = 1 + self.solve(i + 1, i)

        noTake = self.solve(i + 1, lastIdx)

        self.dp[i][lastIdx + 1] = max(take, noTake)

        return self.dp[i][lastIdx + 1]

    # Function to find length of longest increasing subsequence.
    def lis(self, arr):
        self.arr = arr
        self.n = len(arr)

        self.dp = [[-1 for i in range(self.n + 1)] for j in range(self.n)]

        return self.solve(0, -1)


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    for _ in range(int(input())):
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.lis(a))
        print("~")
# } Driver Code Ends
