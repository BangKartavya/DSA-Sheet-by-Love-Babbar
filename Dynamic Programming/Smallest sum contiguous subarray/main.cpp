//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int smallestSumSubarray(vector<int>& a) {
            int currSum = 0;
            int mini = INT_MAX;

            int n = a.size();

            for(int i = 0; i < n; i++) {
                currSum += a[i];
                if(currSum < mini) mini = currSum;
                if(currSum > 0) currSum = 0;
            }

            return mini;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends