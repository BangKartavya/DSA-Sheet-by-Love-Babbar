//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
    public:
        int celebrity(vector<vector<int>>& mat) {
            int n = mat.size();

            vector<int> row(n);
            vector<int> col(n);

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    row[i] += mat[i][j];
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    col[i] += mat[j][i];
                }
            }

            for(int i = 0; i < n; i++) {
                if(col[i] == n && row[i] == 1) return i;
            }

            return -1;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends