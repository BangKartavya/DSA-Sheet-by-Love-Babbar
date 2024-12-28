//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    public:
        bool isBipartite(vector<vector<int>>& adj) {
            int n = adj.size();

            vector<bool> vis(n, false);
            vector<int> colour(n, INT_MAX);

            queue<pair<int, int>> q;
            for(int i = 0; i < n; i++) {
                if(vis[i]) continue;

                q.push({i, 0}); // {node,colour}
                vis[i] = true;

                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    int node = p.first;
                    int c = p.second;
                    colour[node] = c;

                    for(auto it : adj[node]) {
                        if(vis[it] && colour[it] == colour[node]) return false;
                        if(!vis[it]) {
                            vis[it] = true;
                            q.push({it, !c});
                        }
                    }
                }
            }
            return true;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if(ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends