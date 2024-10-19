//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int> findDuplicates(vector<int>& arr) {
            if(arr.size() <= 1) return {};

            map<int, int> mp;

            for(auto i : arr)
                mp[i]++;

            vector<int> ans;

            for(auto it : mp)
                if(it.second > 1) ans.push_back(it.first);

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while(t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while(ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.findDuplicates(a);

        // Print the result in the required format
        if(result.empty()) {
            cout << "[]"; // Print empty brackets if no duplicates are found
        } else {
            for(int i = 0; i < result.size(); i++) {
                if(i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl; // Ensure new line after each test case output
    }

    return 0;
}
G
// } Driver Code Ends