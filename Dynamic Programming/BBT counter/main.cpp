//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
        vector<int> dp;
        int solve(int h) {
            if(h == 1 || h == 0) return 1;

            if(dp[h] != -1) return dp[h];

            return dp[h] = countBT(h - 1) * (2 * countBT(h - 2) + countBT(h - 1));
        }

    public:
        int countBT(int h) {
            dp.resize(10, -1);
            return solve(h);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int h;
        cin >> h;
        Solution ob;
        cout << ob.countBT(h) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends