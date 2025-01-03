//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int isPalindrome(string &s) {
        int n = s.size();
        for(int i = 0;i<n/2;i++) {
            if(s[i] != s[n-i-1]) return 0;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPalindrome(s) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends