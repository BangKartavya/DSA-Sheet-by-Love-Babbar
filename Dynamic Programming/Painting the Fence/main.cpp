//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int n;
    
    vector<vector<int>> dp;
    
    int solve(int i, int k) {
        
        if(i == 1) return k;
        
        if(i == 2) return k*k;
        
        if(dp[i][k] != -1) return dp[i][k];
        
        long long int same = (k-1) * solve(i-1,k);
        long long int different = (k-1) * solve(i-2,k);
        
        return dp[i][k] = same + different;
    }
  public:
    int countWays(int n, int k) {
        this->n = n;
        
        dp.resize(n+1,vector<int>(k+1,-1));
        
        return solve(n,k);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends