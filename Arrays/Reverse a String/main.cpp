//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
        string reverseString(string& s) {
            int n = s.size();
            string ans;

            for(int i = 0; i < n; i++)
                ans += s[n - i - 1];

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.reverseString(s) << endl;
    }
    return 0;
}

// } Driver Code Ends