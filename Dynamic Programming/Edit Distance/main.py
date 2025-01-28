class Solution:
    def solve(self, i, j):
        if i < 0:
            return j + 1
        if j < 0:
            return i + 1

        if self.dp[i][j] != -1:
            return self.dp[i][j]

        if self.s1[i] == self.s2[j]:
            return self.solve(i - 1, j - 1)

        else:
            insertion = 1 + self.solve(i, j - 1)
            replace = 1 + self.solve(i - 1, j - 1)
            deletion = 1 + self.solve(i - 1, j)

            self.dp[i][j] = min(insertion, replace, deletion)

        return self.dp[i][j]

    def editDistance(self, s1, s2):
        n = len(s1)
        m = len(s2)

        self.s1 = s1
        self.s2 = s2

        self.dp = [[-1 for i in range(m)] for j in range(n)]

        return self.solve(n - 1, m - 1)


# {
# Driver Code Starts
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s1 = input()
        s2 = input()
        ob = Solution()
        ans = ob.editDistance(s1, s2)
        print(ans)
        print("~")

# } Driver Code Ends
