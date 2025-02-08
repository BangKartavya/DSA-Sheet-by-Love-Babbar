//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<pair<int, int>> vp;
        int n;
        vector<vector<int>> dp;

        int solve(int i, int capacity) {
            if(capacity == 0) return 0;
            if(capacity < 0) return INT_MIN;
            if(i == n) return 0;

            if(dp[i][capacity] != -1) return dp[i][capacity];

            int take = INT_MIN;

            if(vp[i].second <= capacity) {
                take = vp[i].first + solve(i, capacity - vp[i].second);
            }

            int noTake = solve(i + 1, capacity);

            return dp[i][capacity] = max(take, noTake);
        }

    public:
        int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
            n = val.size();
            dp.resize(n + 1, vector<int>(capacity + 1, -1));
            for(int i = 0; i < n; i++) {
                vp.push_back({val[i], wt[i]});
            }

            return solve(0, capacity);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while(ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while(ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends