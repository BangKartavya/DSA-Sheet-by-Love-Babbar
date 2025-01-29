//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int dp[20];

        int solve(int n) {
            if(n == 3) return 4;
            if(n == 2) return 2;
            if(n == 1) return 1;

            if(dp[n] != -1) return dp[n];

            return dp[n] = solve(n - 1) + (n - 1) * solve(n - 2);
        }

    public:
        int countFriendsPairings(int n) {
            memset(dp, -1, sizeof(dp));

            return solve(n);
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
        cout << ob.countFriendsPairings(n);
        cout << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends