//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(string& a,string& b,int i,int j,vector<vector<int>>& dp) {
	        if(i == a.size()) {
	            return 0;
	        }
	        if(j == b.size()) {
	            return 0;
	        }
	        
	        if(dp[i][j] != -1) return dp[i][j];
	        
	        if(a[i] == b[j] && i != j) dp[i][j] = 1 + solve(a,b,i+1,j+1,dp);
	        else {
	            dp[i][j] = max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
	        }
	        
	        return dp[i][j];
	    }
		int LongestRepeatingSubsequence(string str){
            
            string a = str;
            string b = str;
            
            vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
            
            return solve(a,b,0,0,dp);
            
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends