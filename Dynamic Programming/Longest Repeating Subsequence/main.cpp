#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution {
    private:
        int n;
        std::string s;
        std::vector<std::vector<int>> dp;

        int solve(int i, int j) {
            if(j >= n) return 0;

            if(i >= n) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            if(s[i] == s[j] && i != j) return dp[i][j] = 1 + solve(i + 1, j + 1);

            else {
                return dp[i][j] = std::max(solve(i + 1, j), solve(i, j + 1));
            }
        }

    public:
        int LongestRepeatingSubsequence(std::string& s) {
            this->s = s;
            n = s.size();

            dp.resize(n, std::vector<int>(n, -1));

            return solve(0, 0);
        }
};
