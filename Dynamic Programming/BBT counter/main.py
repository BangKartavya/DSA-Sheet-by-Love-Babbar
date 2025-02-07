# User function Template for python3
class Solution:
    def solve(self, h):
        if h == 0 or h == 1:
            return 1

        if self.dp[h] != -1:
            return self.dp[h]

        self.dp[h] = self.solve(h - 1) * (2 * self.solve(h - 2) + self.solve(h - 1))

        return self.dp[h]

    def countBT(self, h):
        self.dp = [-1] * 10

        return self.solve(h)


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        h = int(input())

        ob = Solution()
        print(ob.countBT(h))

        print("~")

# } Driver Code Ends
