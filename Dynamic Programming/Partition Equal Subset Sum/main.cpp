//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> arr;
        int n;
        int dp = -1;
        int sum;

        bool solve(int i, int s1) {
            if(i >= n) {
                if(2 * s1 != sum) return false;

                return dp = true;
            }

            if(2 * s1 > sum) return false;

            if(dp != -1) return dp;

            int takeS1 = solve(i + 1, s1 + arr[i]);
            int takeS2 = solve(i + 1, s1);

            return takeS1 || takeS2;
        }

    public:
        bool equalPartition(vector<int>& arr) {
            this->arr = arr;
            n = arr.size();

            sum = accumulate(begin(arr), end(arr), 0);

            if(sum % 2 != 0) return false;

            solve(0, 0);

            return dp == -1 ? false : true;
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

        Solution ob;
        if(ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends