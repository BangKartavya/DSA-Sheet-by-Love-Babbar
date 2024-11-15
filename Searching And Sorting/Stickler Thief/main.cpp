//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution {
    public:
        int dp[100005];
        // Function to find the maximum money the thief can get.
        int helper(vector<int>& arr, int n) {
            if(n <= 0) return 0;
            if(n == 1) return arr[0];

            if(dp[n] != -1) return dp[n];

            int picked = arr[n - 1] + helper(arr, n - 2);
            int notPicked = helper(arr, n - 1);

            return dp[n] = max(picked, notPicked);
        }
        int findMaxSum(vector<int>& arr) {
            memset(dp, -1, sizeof(dp));

            int n = arr.size();
            helper(arr, n);

            return dp[n];
        }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends