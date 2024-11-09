//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[505][505];
    
    int lcs(string& s1,string& s2,int n,int m) {
        if(n == 0 || m == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s1[n-1] == s2[m-1]) {
            return dp[n][m] = 1 + lcs(s1,s2,n-1,m-1);
        }
        else return dp[n][m] = max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
    }
    
    int countMin(string s){
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        
        string s2 = s;
        reverse(begin(s2),end(s2));
        
        return n-lcs(s,s2,n,n);
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    
cout << "~" << "\n";
}
return 0;
}


// } Driver Code Ends