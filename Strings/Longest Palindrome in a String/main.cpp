//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    string longestPalin (string s) {
        int n = s.size();
        
        if(n < 2) return s;
        
        bool dp[n][n];
        int cnt = -1;
        string ans = "";
        for(int g = 0;g<n;g++) {
            for(int i=0,j = g;j<n;i++,j++) {
                if(g==0) dp[i][j] = true;
                else if(g==1) {
                   dp[i][j] = (s[i] == s[j]); 
                }
                else {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }
                
                if(dp[i][j] && cnt < j-i+1) {
                    ans = s.substr(i,j-i+1);
                    cnt = ans.size();
                }
                
                cout << "i,j : " << i << "," << j << endl;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends