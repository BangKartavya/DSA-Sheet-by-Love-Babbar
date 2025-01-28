//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> arr;
        int n;
        vector<vector<int>> dp;

        int solve(int start, int end) {
            if(start == end) return 0;

            if(dp[start][end] != -1) return dp[start][end];

            int mini = INT_MAX;

            for(int k = start; k < end; k++) {
                mini = min(mini, arr[start - 1] * arr[k] * arr[end] + solve(start, k) + solve(k + 1, end));
            }

            return dp[start][end] = mini;
        }

    public:
        int matrixMultiplication(vector<int>& arr) {
            n = arr.size();
            dp.resize(n, vector<int>(n, -1));
            this->arr = arr;

            if(n == 2) return 0;

            return solve(1, n - 1);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while(t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while(ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl
             << "~\n";
    }

    return 0;
}

// } Driver Code Ends