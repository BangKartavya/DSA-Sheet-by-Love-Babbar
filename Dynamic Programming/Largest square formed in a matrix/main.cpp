//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<vector<int>> mat;
        int n;
        int m;

        int maxi = 0;
        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i >= n || j >= m) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            int right = solve(i, j + 1);
            int down = solve(i + 1, j);
            int diag = solve(i + 1, j + 1);

            if(mat[i][j] == 1) {
                maxi = max(maxi, 1 + min({right, down, diag}));
                return dp[i][j] = 1 + min({right, down, diag});
            }

            return dp[i][j] = 0;
        }

    public:
        int maxSquare(vector<vector<int>>& mat) {
            this->mat = mat;
            n = mat.size();
            m = mat[0].size();

            dp.resize(n, vector<int>(m, -1));

            solve(0, 0);
            return maxi;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(mat) << "\n"
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends