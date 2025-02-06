//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
    public:
        template <class T>
        static void input(vector<T>& A, int n) {
            for(int i = 0; i < n; i++) {
                scanf("%d ", &A[i]);
            }
        }

        template <class T>
        static void print(vector<T>& A) {
            for(int i = 0; i < A.size(); i++) {
                cout << A[i] << " ";
            }
            cout << endl;
        }
};

// } Driver Code Ends

class Solution {
    private:
        vector<int> cost;
        int n;
        int w;
        vector<vector<int>> dp;
        int solve(int i, int currWeight) {
            if(i >= n) return 1e9;
            if(currWeight + (i + 1) == w && cost[i] != -1) return cost[i];
            if(currWeight > w) return 1e9;

            if(dp[i][currWeight] != -1) return dp[i][currWeight];

            int take = INT_MAX;

            if(currWeight + (i + 1) <= w && cost[i] != -1) {
                take = cost[i] + solve(i, currWeight + (i + 1));
            }

            int noTake = solve(i + 1, currWeight);

            return dp[i][currWeight] = min(take, noTake);
        }

    public:
        int minimumCost(int n, int w, vector<int>& cost) {
            this->cost = cost;
            this->n = n;
            this->w = w;
            dp.resize(n, vector<int>(w + 5, -1));
            int result = solve(0, 0);
            return result < 1e9 ? result : -1;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends