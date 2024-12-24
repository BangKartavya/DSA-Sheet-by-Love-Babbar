//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int dirX[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dirY[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

        int ans = INT_MAX;

    public:
        // Function to find out minimum steps Knight needs to reach target position.
        int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
            bool vis[N + 1][N + 1];
            memset(vis, false, sizeof(vis));

            if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) return 0;

            queue<vector<int>> q;
            q.push({KnightPos[0], KnightPos[1], 0});

            while(!q.empty()) {
                vector<int> top = q.front();
                q.pop();

                vis[top[0]][top[1]] = true;

                for(int i = 0; i < 8; i++) {
                    int newX = top[0] + dirX[i];
                    int newY = top[1] + dirY[i];

                    if(newX < 1 || newX > N || newY < 1 || newY > N) continue;

                    if(newX == TargetPos[0] && newY == TargetPos[1]) {
                        ans = min(ans, top[2] + 1);
                        break;
                    }

                    if(!vis[newX][newY]) {
                        vis[newX][newY] = true;
                        q.push({newX, newY, top[2] + 1});
                    }
                }
            }

            return ans == INT_MAX ? -1 : ans;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends