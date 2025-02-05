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
    
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(j >= m || j < 0) return 0;
        if(i == n-1) return mat[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int diagRight = solve(i+1,j+1);
        int down = solve(i+1,j);
        int diagLeft = solve(i+1,j-1);
        
        int maxi = mat[i][j] + max(diagRight,max(down,diagLeft));
        
        return dp[i][j] = maxi;
    }
  public:
    int maximumPath(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int ans = 0;
        
        for(int i = 0;i<m;i++) {
            int res = solve(0,i);
            ans = max(ans,res);
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.maximumPath(mat) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends