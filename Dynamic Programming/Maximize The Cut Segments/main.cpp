//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int x;
        int y;
        int z;

        vector<int> dp;

        int solve(int n) {
            if(n == 0) return 0;

            if(n < 0) return INT_MIN;

            if(dp[n] != -1) return dp[n];

            int cutX = 1 + solve(n - x);
            int cutY = 1 + solve(n - y);
            int cutZ = 1 + solve(n - z);

            return dp[n] = max({cutX, cutY, cutZ});
        }

    public:
        // Function to find the maximum number of cuts.
        int maximizeTheCuts(int n, int x, int y, int z) {
            this->x = x;
            this->y = y;
            this->z = z;

            dp.resize(n + 1, -1);

            int answer = solve(n);

            return answer >= 0 ? answer : 0;
        }
};

//{ Driver Code Starts.
int main() {
    // taking testcases
    int t;
    cin >> t;
    while(t--) {
        // taking length of line segment
        int n;
        cin >> n;

        // taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        // calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends