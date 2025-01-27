//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    vector<vector<int>> dp{38,vector<int>(37,-1)};
    
  public:
    int nCr(int n, int r) {
        if(r > n) return 0;
        
        if(r == 0) return 1;
        if(r == n) return 1;
        
        if(dp[n][r] != -1) return dp[n][r];
        
        
        return dp[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends