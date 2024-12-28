//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Position this line where user code will be pasted.
class Solution {
    private:
        void dfs(int node, bool rev, vector<vector<int>>& adj, stack<int>& sorted_finishing_time, vector<bool>& vis) {
            vis[node] = true;
            if(!rev) {
                for(auto i : adj[node]) {
                    if(!vis[i]) {
                        dfs(i, false, adj, sorted_finishing_time, vis);
                    }
                }
                sorted_finishing_time.push(node);
            } else {
                for(auto i : adj[node]) {
                    if(!vis[i]) {
                        dfs(i, true, adj, sorted_finishing_time, vis);
                    }
                }
            }
        }

    public:
        int kosaraju(vector<vector<int>>& adj) {
            int n = adj.size();
            vector<bool> vis(n, false);
            stack<int> sorted_finishing_time;

            for(int i = 0; i < n; i++) {
                if(!vis[i]) dfs(i, false, adj, sorted_finishing_time, vis);
            }

            vector<vector<int>> rev_adj(n);

            for(int i = 0; i < n; i++) {
                vis[i] = false;
                for(auto j : adj[i]) {
                    rev_adj[j].push_back(i);
                }
            }
            int cnt = 0;

            while(!sorted_finishing_time.empty()) {
                int i = sorted_finishing_time.top();

                if(vis[i]) {
                }

                else {
                    dfs(i, true, rev_adj, sorted_finishing_time, vis);
                    cnt++;
                }
                sorted_finishing_time.pop();
            }

            return cnt;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends