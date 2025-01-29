//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  
    vector<vector<int>> mat;
    vector<vector<int>> dp;
  
    int n;
    int m;
  
    int solve(int x,int y) {
        if(x >= n || x < 0) return 0;
        if(y >= m) return 0;
        if(y == m-1) {
            return mat[x][y];
        }
        
        
        if(dp[x][y] != -1) return dp[x][y];
        
        int topRight = solve(x-1,y+1);
        int right = solve(x,y+1);
        int bottomRight = solve(x+1,y+1);
        
        return dp[x][y] = mat[x][y] + max({topRight,right,bottomRight});
    }
  public:
    int maxGold(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        
        dp.resize(n,vector<int>(m,-1));
        
        int answer = 0;
        for(int i = 0;i<n;i++) {
            answer = max(answer,solve(i,0));
        }
        
        return answer;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        }
        cin.ignore();
        Solution ob;
        cout << ob.maxGold(mat) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends