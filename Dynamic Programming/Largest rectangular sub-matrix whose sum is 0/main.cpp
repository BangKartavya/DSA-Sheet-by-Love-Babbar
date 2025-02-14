//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int zeroSumSubmat(vector<vector<int>>& mat) {
            int n = mat.size();
            int m = mat[0].size();
            int maxi = 0;

            for(int i = 0; i < n; i++) {
                vector<int> tempRow(m);
                for(int j = i; j < n; j++) {
                    for(int c = 0; c < m; c++) {
                        tempRow[c] += mat[j][c];
                    }
                    unordered_map<int, int> mp;
                    int sum = 0;
                    for(int c = 0; c < m; c++) {
                        sum += tempRow[c];
                        if(sum == 0) {
                            maxi = max(maxi, (j - i + 1) * (c + 1));
                        }
                        if(mp.find(sum) != mp.end()) {
                            maxi = max(maxi, (j - i + 1) * (c - mp[sum]));
                        } else mp[sum] = c;
                    }
                    if(sum == 0) maxi = max(maxi, (j - i + 1) * (m));
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
        int n, m;
        cin >> n >> m;

        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.zeroSumSubmat(mat);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends