//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    string s;
    int n;
    
    vector<vector<vector<int>>> dp;
    
    int solve(int i, int j, bool isTrue) {
        if(i > j) return 0;
        
        if(i == j) {
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int res = 0;
        
        for(int k = i+1;k<j;k+=2) {
            int leftTrue = solve(i,k-1,true);
            int leftFalse = solve(i,k-1,false);
            int rightTrue = solve(k+1,j,true);
            int rightFalse = solve(k+1,j,false);
            
            if(s[k] == '&') {
                if(isTrue) res += (leftTrue * rightTrue);
                else res += (leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue);
            }
            if(s[k] == '|') {
                if(isTrue) res += (leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue);
                else res += (leftFalse * rightFalse);
            }
            if(s[k] == '^') {
                if(isTrue) res += (leftTrue * rightFalse + leftFalse * rightTrue);
                else res += (leftFalse * rightFalse + leftTrue * rightTrue);
                
            }
        }
        
        return dp[i][j][isTrue] = res;
    }
    
  public:
    int countWays(string s) {
        this->s = s;
        n = s.size();
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(0,n-1,true);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends