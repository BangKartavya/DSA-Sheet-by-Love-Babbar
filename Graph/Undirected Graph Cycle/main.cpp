//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool detect(int src, vector<vector<int>>& adj, int vis[]) {
            int n = adj.size();
            queue<pair<int, int>> q;
            q.push({src, -1});

            vis[src] = true;

            while(!q.empty()) {
                pair<int, int> top = q.front();
                q.pop();
                int node = top.first;
                int parent = top.second;

                for(auto i : adj[node]) {
                    if(!vis[i]) {
                        vis[i] = true;
                        q.push({i, node});
                    }

                    else if(parent != i) return true;
                }
            }
            return false;
        }

    public:
        // Function to detect cycle in an undirected graph.
        bool isCycle(vector<vector<int>>& adj) {
            int n = adj.size();
            int vis[n];
            memset(vis, 0, sizeof(vis));

            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    if(detect(i, adj, vis)) return true;
                }
            }

            return false;
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
        bool ans = obj.isCycle(adj);
        if(ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends