//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    string s;
    int n;
    
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(i >= n || j < i) return 0;
        
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) {
            return dp[i][j] = 1 + solve(i+1,j) + solve(i,j-1);
        }
        
        return dp[i][j] = solve(i+1,j) + solve(i,j-1)-solve(i+1,j-1);
    }
    
  public:
    int countPS(string &s) {
        this->s = s;
        n = s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(0,n-1);
        
    }
};

//{ Driver Code Starts.
//  Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.countPS(str);
        cout << ans << endl;
    }
}
// } Driver Code Ends