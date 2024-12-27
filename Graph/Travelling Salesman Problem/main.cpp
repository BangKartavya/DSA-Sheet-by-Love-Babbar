//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> cost;
        vector<vector<int>> dp;
        int n;
        int helper(int pos, int mask) {
            if(mask == (1 << n) - 1) {
                return cost[pos][0];
            }

            if(dp[pos][mask] != -1) return dp[pos][mask];
            int ans = INT_MAX;

            for(int i = 0; i < n; i++) {
                if((mask & (1 << i)) == 0) {
                    ans = min(ans, cost[pos][i] + helper(i, mask | (1 << i)));
                }
            }

            return dp[pos][mask] = ans;
        }

    public:
        int tsp(vector<vector<int>>& cost) {
            this->cost = cost;
            n = cost.size();
            dp.resize(n, vector<int>((int)pow(2, n), -1));

            return helper(0, 1);
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.tsp(cost);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends