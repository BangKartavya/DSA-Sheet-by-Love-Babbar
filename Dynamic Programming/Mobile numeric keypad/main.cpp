//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int mat[4][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1}};

        vector<vector<long long>> dp;

        long long int solve(int i, int j, int n) {
            if(n == 1) return 1;

            if(dp[mat[i][j]][n] != -1) return dp[mat[i][j]][n];

            long long int take = solve(i, j, n - 1);
            long long int left = (j - 1 >= 0 && mat[i][j - 1] != -1) ? solve(i, j - 1, n - 1) : 0;
            long long int right = (j + 1 < 3 && mat[i][j + 1] != -1) ? solve(i, j + 1, n - 1) : 0;
            long long int down = (i + 1 < 4 && mat[i + 1][j] != -1) ? solve(i + 1, j, n - 1) : 0;
            long long int up = (i - 1 >= 0 && mat[i - 1][j] != -1) ? solve(i - 1, j, n - 1) : 0;

            return dp[mat[i][j]][n] = take + left + right + down + up;
        }

    public:
        long long getCount(int n) {
            dp.resize(10, vector<long long>(n + 1, -1));
            long long int ans = 0;

            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 3; j++) {
                    if(mat[i][j] != -1)
                        ans += solve(i, j, n);
                }
            }

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends