//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        // Function to find distance of nearest 1 in the grid for each cell.
        vector<vector<int>> nearest(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int dirX[4] = {0, -1, 0, 1};
            int dirY[4] = {1, 0, -1, 0};

            vector<vector<int>> result(n, vector<int>(m, 0));

            queue<pair<int, int>> q; // {x,y}
            vector<vector<bool>> vis(n, vector<bool>(m, false));

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = true;
                    }
                }
            }

            int dist = 0;

            while(!q.empty()) {
                int siz = q.size();
                dist++;
                while(siz--) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k = 0; k < 4; k++) {
                        int newX = x + dirX[k];
                        int newY = y + dirY[k];

                        if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;

                        if(!vis[newX][newY]) {
                            result[newX][newY] = dist;
                            vis[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
            }

            return result;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for(auto i : ans) {
            for(auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends