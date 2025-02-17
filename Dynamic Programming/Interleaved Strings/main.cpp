//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    string s1;
    string s2;
    string s3;
    int n;
    int m;
    int l;
    
    vector<vector<int>> dp;
    
    bool solve(int i, int j, int k) {
        if(i >= n && j >= m && k >= l) return true;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i < n && j < m && s1[i] == s2[j] && s1[i] == s3[k]) return dp[i][j] = (solve(i+1,j,k+1) || solve(i,j+1,k+1));
        
        else if(i < n && s1[i] == s3[k]) return dp[i][j] = solve(i+1,j,k+1);
        
        else if(j < m && s2[j] == s3[k]) return dp[i][j] = solve(i,j+1,k+1);
        
        else return dp[i][j] = false;
        
    }
    
  public:
    /*You are required to complete this method */
    bool isInterleave(string& s1, string& s2, string& s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        if(s1[0] != s3[0] && s2[0] != s3[0]) return false;
        
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        n = s1.size();
        m = s2.size();
        l = s3.size();
        dp.resize(n+5,vector<int>(m+5,-1));
        
        return solve(0,0,0);
            
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        if (obj.isInterleave(a, b, c))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends