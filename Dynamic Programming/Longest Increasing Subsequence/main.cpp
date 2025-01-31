#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    private:
        std::vector<int> arr;
        int n;
        std::vector<std::vector<int>> dp;

        int solve(int i, int lastIdx) {
            if(i >= n) return 0;

            if(dp[i][lastIdx] != -1) return dp[i][lastIdx];

            int take = INT_MIN;

            if(arr[i] > arr[lastIdx]) {
                take = 1 + solve(i + 1, i);
            }
            int noTake = solve(i + 1, lastIdx);

            return dp[i][lastIdx] = std::max(take, noTake);
        }

    public:
        // Function to find length of longest increasing subsequence.
        int lis(std::vector<int>& arr) {
            this->arr = arr;
            n = arr.size();

            dp.resize(n, std::vector<int>(n + 1, -1));

            int result = 0;

            for(int i = 0; i < n; i++) {
                result = std::max(result, 1 + solve(i, i));
            }

            return result;
        }
};
