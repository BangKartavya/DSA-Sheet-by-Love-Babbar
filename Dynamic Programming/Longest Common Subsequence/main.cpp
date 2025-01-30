//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  private:
    string s1;
    string s2;
    
    int n;
    int m;
    
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(i >= n || j >= m) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + solve(i+1,j+1);
        
        else return dp[i][j] = max(solve(i+1,j),solve(i,j+1));
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(string& s1, string& s2) {
        this->s1 = s1;
        this->s2 = s2;
        n = s1.size();
        m = s2.size();
        
        dp.resize(n,vector<int>(m,-1));
        
        return solve(0,0);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends