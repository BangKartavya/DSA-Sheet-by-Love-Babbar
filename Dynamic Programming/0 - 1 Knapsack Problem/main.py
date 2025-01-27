# User function Template for python3


class Solution:
    # Function to return max value that can be put in knapsack of capacity.

    def solve(self, i, capacity):
        if i == 0:
            if self.v[i][0] <= capacity:
                self.dp[capacity][i] = self.v[i][1]
            else:
                self.dp[capacity][i] = 0

            return self.dp[capacity][i]

        if self.dp[capacity][i] != -1:
            return self.dp[capacity][i]

        noTake = self.solve(i - 1, capacity)
        take = 0

        if self.v[i][0] <= capacity:
            take = self.v[i][1] + self.solve(i - 1, capacity - self.v[i][0])

        self.dp[capacity][i] = max(take, noTake)

        return self.dp[capacity][i]

    def knapSack(self, capacity, val, wt):
        n = len(val)
        self.v = [(wt[i], val[i]) for i in range(n)]

        self.dp = [[-1 for i in range(n)] for j in range(capacity + 1)]

        self.solve(n - 1, capacity)

        return self.dp[capacity][n - 1]


# {
# Driver Code Starts
if __name__ == "__main__":
    test_cases = int(input())
    for _ in range(test_cases):
        # Read capacity
        capacity = int(input())
        values = list(
            map(int, input().strip().split())
        )  # Using 'values' instead of 'val'
        weights = list(
            map(int, input().strip().split())
        )  # Using 'weights' instead of 'wt'
        ob = Solution()
        print(ob.knapSack(capacity, values, weights))
        print("~")

# } Driver Code Ends
