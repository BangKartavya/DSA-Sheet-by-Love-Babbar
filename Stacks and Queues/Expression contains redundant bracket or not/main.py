class Solution:

    def checkRedundancy(self, s):
        stk = []

        for ch in s:
            if ch == "(" or ch == "+" or ch == "-" or ch == "/" or ch == "*":
                stk.append(ch)
            else:
                if ch == ")":
                    if stk[-1] == "(":
                        return 1

                    while len(stk) != 0 and stk[-1] != "(":
                        stk.pop()
                    stk.pop()
        return 0


# {
# Driver Code Starts

if __name__ == "__main__":
    for _ in range(int(input())):
        s = input()
        print(Solution().checkRedundancy(s))

        print("~")
# } Driver Code Ends
