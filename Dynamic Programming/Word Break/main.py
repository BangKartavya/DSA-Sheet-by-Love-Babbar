# User function Template for python3


class Solution:
    def wordBreak(self, n, s, dictionary):
        dp = [False] * (len(s) + 1)

        dp[len(s)] = True

        for i in range(len(s) - 1, -1, -1):
            for word in dictionary:
                if i + len(word) <= len(s) and s[i : i + len(word)] == word:
                    dp[i] = dp[i + len(word)]

                if dp[i]:
                    break

        return dp[0]


# {
# Driver Code Starts
if __name__ == "__main__":
    test_case = int(input())

    for _ in range(test_case):
        n = int(input())
        dictionary = [word for word in input().strip().split()]
        s = input().strip()
        ob = Solution()
        res = ob.wordBreak(n, s, dictionary)
        if res:
            print(1)
        else:
            print(0)
        print("~")
# } Driver Code Ends
