//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Complete back-end function template for C++

// } Driver Code Ends
// User function template for C++

class Solution {
    public:
        // nums: given vector
        // return the Product vector P that hold product except self at each index
        vector<long long> productExceptSelf(vector<int>& arr) {
            int n = arr.size();

            vector<long long int> lhs(n, 0);
            vector<long long int> rhs(n, 0);

            lhs[1] = arr[0];
            rhs[n - 2] = arr[n - 1];

            for(int i = 2; i < n; i++) {
                lhs[i] = lhs[i - 1] * arr[i - 1];
                rhs[n - i - 1] = rhs[n - i] * arr[n - i];
            }

            vector<long long int> ans(n, 0);

            ans[0] = rhs[0];
            ans[n - 1] = lhs[n - 1];

            for(int i = 1; i < n - 1; i++) {
                ans[i] = lhs[i] * rhs[i];
            }

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // To ignore newline character after t input

    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while(ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<long long> vec = obj.productExceptSelf(arr); // Function call

        for(int i = 0; i < vec.size(); i++) { // Print the output
            cout << vec[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends