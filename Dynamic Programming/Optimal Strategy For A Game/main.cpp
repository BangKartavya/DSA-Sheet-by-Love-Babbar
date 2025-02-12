//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find the maximum possible amount of money we can win.
class Solution {
  vector<int> arr;
  int n;
  
  vector<vector<vector<int>>> dp;
  
  int solve(int s,int e,bool myTurn) {
      if(s >= n || e < s) return 0;
      
      if(dp[s][e][myTurn] != -1) return dp[s][e][myTurn];
      
      int takeStart = solve(s+1,e,!myTurn);
      int takeEnd = solve(s,e-1,!myTurn);
      
      if(myTurn) {
          dp[s][e][myTurn] = max(arr[s] + takeStart,arr[e] + takeEnd);
      }
      else {
          dp[s][e][myTurn] = min(takeStart,takeEnd);
      }
      
      return dp[s][e][myTurn];
  }
  
  public:
    int maximumAmount(vector<int> &arr) {
        this->arr = arr;
        n = arr.size();
        
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        
        return solve(0,n-1,true);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximumAmount(a) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends