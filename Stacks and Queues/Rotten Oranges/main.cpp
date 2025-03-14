//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        // Function to find minimum time required to rot all oranges.
        int orangesRotting(vector<vector<int>>& mat) {
            int dirX[4] = {0, -1, 0, 1};
            int dirY[4] = {1, 0, -1, 0};

            int n = mat.size();
            int m = mat[0].size();

            queue<vector<int>> q; // {x,y,time}
            vector<vector<bool>> vis(n, vector<bool>(m, false));

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == 2) {
                        q.push({i, j, 0});
                        vis[i][j] = true;
                    }
                }
            }

            int ans = 0;

            while(!q.empty()) {
                int x = q.front()[0];
                int y = q.front()[1];
                int t = q.front()[2];
                q.pop();

                bool infected = false;

                for(int k = 0; k < 4; k++) {
                    int newX = x + dirX[k];
                    int newY = y + dirY[k];

                    if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                    if(!vis[newX][newY] && mat[newX][newY] == 1) {
                        infected = true;
                        vis[newX][newY] = true;
                        q.push({newX, newY, t + 1});
                    }
                }
                ans = t;
            }

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mat[i][j] == 1 && !vis[i][j]) return -1;
                }
            }

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends