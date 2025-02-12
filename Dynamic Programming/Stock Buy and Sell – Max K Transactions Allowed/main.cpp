//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> arr;
        int k;
        int n;

        vector<vector<int>> dp;

        int solve(int i, int transactionCount) {
            if(i >= n || transactionCount == 2 * k) return 0;

            if(dp[i][transactionCount] != -1) return dp[i][transactionCount];

            if(transactionCount % 2 == 0) {
                return dp[i][transactionCount] = max(-arr[i] + solve(i + 1, transactionCount + 1), solve(i + 1, transactionCount));
            } else {
                return dp[i][transactionCount] = max(arr[i] + solve(i + 1, transactionCount + 1), solve(i + 1, transactionCount));
            }
        }

    public:
        int maxProfit(vector<int>& arr, int k) {
            this->arr = arr;
            n = arr.size();
            this->k = k;
            dp.resize(n + 1, vector<int>(2 * k + 1, -1));
            return solve(0, 0);
        }
};

//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while(iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends