//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        vector<vector<char>> grid;
        vector<vector<bool>> vis;

        int n;
        int m;

        void dfs(int i, int j) {
            vis[i][j] = true;
            for(int k = 0; k < 8; k++) {
                int newX = i + dirX[k];
                int newY = j + dirY[k];

                if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                if(grid[newX][newY] == '1' && !vis[newX][newY]) {
                    dfs(newX, newY);
                }
            }
        }

    public:
        // Function to find the number of islands.
        int numIslands(vector<vector<char>>& grid) {
            n = grid.size();
            m = grid[0].size();
            this->grid = grid;
            vis.resize(n, vector<bool>(m, false));

            int cnt = 0;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == '1') {
                        if(!vis[i][j]) {
                            dfs(i, j);
                            cnt++;
                        }
                    }
                }
            }

            return cnt;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends