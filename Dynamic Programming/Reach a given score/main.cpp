//{ Driver Code Starts
// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution {
    private:
        int points[3] = {3, 5, 10};
        vector<vector<long long int>> dp;

        long long int solve(long long int n, int i) {
            if(n < 0 || i >= 3) return 0;
            if(n == 0) return 1;

            if(dp[n][i] != -1) return dp[n][i];

            int take = solve(n - points[i], i);
            int noTake = solve(n, i + 1);

            return dp[n][i] = take + noTake;
        }

    public:
        // Complete this function
        long long int count(long long int n) {
            dp.resize(n + 1, vector<long long int>(3, -1));
            return solve(n, 0);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        Solution obj;
        cout << obj.count(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends