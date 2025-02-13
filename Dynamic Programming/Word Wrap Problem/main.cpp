//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> arr;
        int n;
        int k;

        vector<vector<int>> dp;

        int solve(int i, int rem) {
            if(i == n) return 0;

            if(dp[i][rem + 1] != -1) {
                return dp[i][rem + 1];
            }

            if(arr[i] > rem) {
                return dp[i][rem + 1] = (rem + 1) * (rem + 1) + solve(i + 1, k - arr[i] - 1);
            }

            else {
                int place = solve(i + 1, rem - arr[i] - 1);
                int dontPlace = (rem + 1) * (rem + 1) + solve(i + 1, k - arr[i] - 1);

                return dp[i][rem + 1] = min(place, dontPlace);
            }
        }

    public:
        int solveWordWrap(vector<int> arr, int k) {
            this->arr = arr;
            this->k = k;
            n = arr.size();
            dp.resize(n + 1, vector<int>(k + 2, -1));
            return solve(0, k);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while(ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while(ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends