//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int countSquares(int N) {
            int ans = 0;

            for(int i = 1; i * i < N; i++) {
                ans++;
            }

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;

        cin >> N;

        Solution ob;
        cout << ob.countSquares(N) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends