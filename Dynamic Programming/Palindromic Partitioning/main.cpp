//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    string s;
    int n;
    vector<int> dp;
    
    
    bool isPal(int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    int solve(int i) {
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int res = INT_MAX;
        
        for(int k = i;k<n;k++) {
            if(isPal(i,k)) {
                // cout << "sub : " << s.substr(i,k-i+1) << endl;
                int cost = 1 + solve(k+1);
                res = min(res, cost);
            }
        }
        
        return dp[i] = res;
    }
  public:
    int palindromicPartition(string &s) {
        this->s = s;
        n = s.size();
        dp.resize(n+2,-1);
        
        return solve(0) - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends