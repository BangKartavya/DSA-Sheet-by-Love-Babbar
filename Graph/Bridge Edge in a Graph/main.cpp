//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find if the given edge is a bridge in graph.
        int isBridge(int V, vector<int> adj[], int c, int d) {
            vector<bool> vis(V, false);
            queue<int> q;
            int bfs_cnt = 0;

            for(int i = 0; i < V; i++) {
                if(vis[i]) continue;

                vis[i] = true;
                q.push(i);

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto it : adj[node]) {
                        if(!vis[it]) {
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                }
                bfs_cnt++;
            }

            vector<int> c_rep;
            vector<int> d_rep;

            for(auto i : adj[c]) {
                if(i != d) c_rep.push_back(i);
            }
            for(auto i : adj[d]) {
                if(i != c) d_rep.push_back(i);
            }

            adj[c] = c_rep;
            adj[d] = d_rep;

            vector<bool> vis2(V, false);

            for(int i = 0; i < V; i++) {
                if(vis2[i]) continue;
                vis2[i] = true;
                q.push(i);

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for(auto it : adj[node]) {
                        if(!vis2[it]) {
                            vis2[it] = true;
                            q.push(it);
                        }
                    }
                }
                bfs_cnt--;
            }

            return bfs_cnt == 0 ? false : true;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while(i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends