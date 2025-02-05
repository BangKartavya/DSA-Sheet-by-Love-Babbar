//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
    public:
        int maxSubstring(string S) {
            int n = S.size();

            int currSum = 0;
            int maxi = INT_MIN;

            for(int i = 0; i < n; i++) {
                int x = (S[i] == '1' ? -1 : 1);
                currSum += x;
                if(currSum > maxi) maxi = currSum;
                if(currSum < 0) currSum = 0;
            }

            return maxi;
        }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends