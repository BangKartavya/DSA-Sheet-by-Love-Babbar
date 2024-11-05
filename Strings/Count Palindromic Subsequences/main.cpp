//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        /*You are required to complete below method */
        int MOD = 1e9 + 7;
        long long counting(string& s, int i, int j, vector<vector<int>>& dp) {
            if(i > j) return 0;

            if(i == j) return 1;

            if(dp[i][j] != -1) return dp[i][j];

            if(s[i] == s[j]) {
                dp[i][j] = (1 + counting(s, i + 1, j, dp) % MOD + counting(s, i, j - 1, dp) % MOD) % MOD;
            } else {
                dp[i][j] = (counting(s, i + 1, j, dp) % MOD + counting(s, i, j - 1, dp) % MOD - counting(s, i + 1, j - 1, dp) % MOD + MOD) % MOD;
            }

            return dp[i][j];
        }

        long long int countPS(string s) {
            int n = s.size();

            vector<vector<int>> dp(n, vector<int>(n, -1));

            return counting(s, 0, n - 1, dp) % MOD;
        }
};

//{ Driver Code Starts.
// Driver program
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends