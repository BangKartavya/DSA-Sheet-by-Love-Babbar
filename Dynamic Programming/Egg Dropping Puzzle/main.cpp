//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> dp;
        int solve(int eggs, int floors) {
            if(eggs == 1) return floors;
            if(floors <= 1) return floors;

            if(dp[eggs][floors] != -1) return dp[eggs][floors];

            int mini = INT_MAX;

            for(int k = 1; k <= floors; k++) {
                mini = min(mini, 1 + max(solve(eggs - 1, k - 1), solve(eggs, floors - k)));
            }

            return dp[eggs][floors] = mini;
        }

    public:
        int eggDrop(int eggs, int floors) {
            if(eggs == 1) return floors;
            if(floors == 1) return floors;

            dp.resize(eggs + 1, vector<int>(floors + 1, -1));

            return solve(eggs, floors);
        }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while(t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends