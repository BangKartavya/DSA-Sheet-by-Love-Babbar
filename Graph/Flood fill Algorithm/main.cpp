//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private: 
    int dirX[4] = {0,0,-1,1};
    int dirY[4] = {1,-1,0,0};
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        bool vis[n][m];
        
        memset(vis,false,sizeof(vis));
        
        if(image[sr][sc] == newColor) return image;
        
        queue<vector<int>> q;
        q.push({sr,sc});
        vis[sr][sc] = true;
        
        while(!q.empty()) {
            vector<int> top = q.front();
            int x = top[0];
            int y = top[1];
            q.pop();
            

            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];
                
                if(newX < 0 || newX >= n || newY < 0 || newY >= m) {
                    continue;
                }
                if(image[newX][newY] == image[sr][sc]) {
                    if(!vis[newX][newY]) {
                        // cout << "newX, newY : " << newX << "," << newY << endl;
                        vis[newX][newY] = true;
                        q.push({newX,newY});
                    
                    }
                }
            
            }
        
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(vis[i][j]) {
                    image[i][j] = newColor;
                }
            }
        }
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends