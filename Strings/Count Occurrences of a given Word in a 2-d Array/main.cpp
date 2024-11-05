//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int ans = 0;

        void dfs(vector<vector<char>>& mat, int i, int j, int idx, string& target) {
            if(i < 0 || i == mat.size() || j < 0 || j == mat[0].size() ||
               idx >= target.size() || target[idx] != mat[i][j]) return;

            if(idx == target.size() - 1) {
                ans++;
                return;
            }
            char temp = mat[i][j];
            mat[i][j] = '0';

            dfs(mat, i + 1, j, idx + 1, target);
            dfs(mat, i - 1, j, idx + 1, target);

            dfs(mat, i, j + 1, idx + 1, target);
            dfs(mat, i, j - 1, idx + 1, target);
            mat[i][j] = temp;
        }

        int findOccurrence(vector<vector<char>>& mat, string target) {
            int n = mat.size();
            int m = mat[0].size();
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    dfs(mat, i, j, 0, target);
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
        int R, C;
        cin >> R >> C;
        vector<vector<char>> mat(R);
        for(int i = 0; i < R; i++) {
            mat[i].resize(C);
            for(int j = 0; j < C; j++)
                cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout << obj.findOccurrence(mat, target) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends