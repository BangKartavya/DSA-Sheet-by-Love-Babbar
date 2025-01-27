# User function Template for python3


class Solution:
    def solve(self, i, target):
        if i == 0:
            self.dp[target][i] = int((target % self.coins[i] == 0))
            return self.dp[target][i]

        if self.dp[target][i] != -1:
            return self.dp[target][i]

        noTake = self.solve(i - 1, target)
        take = 0
        if self.coins[i] <= target:
            take = self.solve(i, target - self.coins[i])

        self.dp[target][i] = take + noTake

        return self.dp[target][i]

    def count(self, coins, Sum):
        self.coins = sorted(coins)

        self.dp = [[-1 for j in range(len(coins))] for i in range(Sum + 1)]

        self.solve(len(coins) - 1, Sum)

        return self.dp[Sum][len(coins) - 1]


# {
# Driver Code Starts
# Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        coins = list(map(int, input().strip().split()))
        sum = int(input())
        ob = Solution()
        print(ob.count(coins, sum))

        print("~")

# } Driver Code Ends
