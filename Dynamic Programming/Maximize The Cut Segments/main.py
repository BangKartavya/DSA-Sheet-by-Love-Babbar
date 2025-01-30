# User function Template for python3


class Solution:
    def solve(self, n):
        if n == 0:
            return 0

        if n < 0:
            return float("-inf")

        if self.dp[n] != -1:
            return self.dp[n]

        cutX = 1 + self.solve(n - self.x)
        cutY = 1 + self.solve(n - self.y)
        cutZ = 1 + self.solve(n - self.z)

        self.dp[n] = max(cutX, cutY, cutZ)

        return self.dp[n]

    # Function to find the maximum number of cuts.
    def maximizeTheCuts(self, n, x, y, z):
        self.x = x
        self.y = y
        self.z = z

        self.dp = [-1] * (n + 1)

        result = self.solve(n)

        if result >= 0:
            return result

        return 0


# {
# Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB
if __name__ == "__main__":
    t = int(input())
    for tcs in range(t):
        n = int(input())
        x = int(input())
        y = int(input())
        z = int(input())
        print(Solution().maximizeTheCuts(n, x, y, z))
        print("~")

# } Driver Code Ends
