//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> dp;
        vector<int> coins;

        int solve(int target, int i) {
            if(i == 0) {
                return dp[target][i] = (target % coins[i] == 0);
            }

            if(dp[target][i] != -1) return dp[target][i];

            int noTake = solve(target, i - 1);

            int take = 0;

            if(coins[i] <= target) {
                take = solve(target - coins[i], i);
            }

            return dp[target][i] = take + noTake;
        }

    public:
        int count(vector<int>& coins, int sum) {
            sort(begin(coins), end(coins));

            this->coins = coins;

            int n = coins.size();

            dp.resize(sum + 1, vector<int>(n, -1));

            solve(sum, n - 1);

            return dp[sum][n - 1] == -1 ? 0 : dp[sum][n - 1];
        }
};

//{ Driver Code Starts.

int main() {
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends