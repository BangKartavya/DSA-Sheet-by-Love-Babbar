//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Item {
        int weight;
        int value;
};

static bool cmp(const Item& a, const Item& b) {
    return a.weight <= b.weight;
}

class Solution {
    private:
        vector<Item> v;
        vector<vector<int>> dp;

        int solve(int i, int capacity) {
            if(i == 0) {
                if(v[i].weight <= capacity) {
                    return dp[capacity][i] = v[i].value;
                } else return dp[capacity][i] = 0;
            }

            if(dp[capacity][i] != -1) return dp[capacity][i];

            int noTake = solve(i - 1, capacity);
            int take = 0;

            if(v[i].weight <= capacity) {
                take = v[i].value + solve(i - 1, capacity - v[i].weight);
            }

            return dp[capacity][i] = max(take, noTake);
        }

    public:
        // Function to return max value that can be put in knapsack of capacity.
        int knapSack(int capacity, vector<int>& val, vector<int>& wt) {
            int n = val.size();
            v.resize(n);
            dp.resize(capacity + 1, vector<int>(n, -1));

            for(int i = 0; i < n; i++) {
                v[i] = {wt[i], val[i]};
            }

            // sort(begin(v),end(v),cmp);

            solve(n - 1, capacity);

            return dp[capacity][n - 1];
        }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while(testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while(ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while(ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends