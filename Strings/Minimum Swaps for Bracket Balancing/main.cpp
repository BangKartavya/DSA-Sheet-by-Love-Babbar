//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int minimumNumberOfSwaps(string S) {
            int open = 0;
            int close = 0;
            int unbal = 0;
            int ans = 0;
            int n = S.size();

            for(int i = 0; i < n; i++) {
                if(S[i] == ']') {
                    close++;
                    if(close > open) unbal = (close - open);
                }
                if(S[i] == '[') {
                    open++;
                    ans += unbal;
                    if(unbal > 0) unbal--;
                }
            }
            return ans;
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
        cout << ob.minimumNumberOfSwaps(S) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends