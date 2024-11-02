//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[105][105];
    
    int func(string& s1,string& s2,int i ,int j) {
        
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
           return dp[i][j] = func(s1,s2,i-1,j-1); 
        }
        
        else {
        
            int insertion = 1 + func(s1,s2,i,j-1);
            int deletion = 1 + func(s1,s2,i-1,j);
            int replace = 1 + func(s1,s2,i-1,j-1);
            
            return dp[i][j] = min({insertion,deletion,replace});;
        }
        
    }
    int editDistance(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return func(s1,s2,s1.size()-1,s2.size()-1);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends