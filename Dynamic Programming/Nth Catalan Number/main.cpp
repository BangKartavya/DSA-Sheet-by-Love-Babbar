//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find the nth catalan number.
        int findCatalan(int n) {
            vector<int> dp(n + 1);
            dp[0] = 1;

            for(int i = 1; i <= n; i++) {
                dp[i] = ((long long)(4 * i - 2) * (long long)dp[i - 1]) / (long long)(i + 1);
            }

            return dp[n];
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.findCatalan(n) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends