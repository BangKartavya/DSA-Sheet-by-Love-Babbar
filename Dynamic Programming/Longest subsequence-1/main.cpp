//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    vector<int> arr;
    int n;
    vector<vector<int>> dp;
    int solve(int i, int lastTookIdx) {
        if(i == n) return 0;
        
        if(dp[i][lastTookIdx+1] != -1) return dp[i][lastTookIdx+1];
        
        int take = 0;
        
        if(lastTookIdx == -1 || abs(arr[lastTookIdx]-arr[i]) == 1) {
            take = 1 + solve(i+1,i);
        }
        
        int noTake = solve(i+1,lastTookIdx);
        
        return dp[i][lastTookIdx+1] = max(take,noTake);
        
    }
  public:
    int longestSubseq(vector<int> &arr) {
        this->arr = arr;
        n = arr.size();
        
        dp.resize(n+1,vector<int>(n+1,-1));
        
        return solve(0,-1);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution sln;
        int res = sln.longestSubseq(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends