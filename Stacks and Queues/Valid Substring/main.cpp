//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for c++
class Solution {
    public:
        int findMaxLen(string& s) {
            int open = 0;
            int close = 0;
            int maxi = 0;
            int n = s.size();

            for(int i = 0; i < n; i++) {
                if(s[i] == '(') open++;
                else close++;

                if(open == close) {
                    maxi = max(maxi, 2 * open);
                } else if(close > open) {
                    open = 0;
                    close = 0;
                }
            }

            open = 0;
            close = 0;

            for(int i = n - 1; i >= 0; i--) {
                if(s[i] == '(') close++;
                else open++;

                if(open == close) {
                    maxi = max(maxi, 2 * open);
                }

                else if(close > open) {
                    open = 0;
                    close = 0;
                }
            }

            return maxi;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends