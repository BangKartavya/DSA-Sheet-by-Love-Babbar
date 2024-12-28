//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User Function Template
class Solution {
    public:
        // Function to find the shortest distance of all the vertices
        // from the source vertex src.
        vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            int n = adj.size();
            vector<int> ans(n, INT_MAX);

            ans[src] = 0;
            pq.push({0, src});

            while(!pq.empty()) {
                pair<int, int> top = pq.top();
                pq.pop();
                int dist = top.first;
                int node = top.second;

                for(auto i : adj[node]) {
                    int newDist = dist + i.second;
                    int newNode = i.first;

                    if(newDist < ans[newNode]) {
                        ans[newNode] = newDist;
                        pq.push({newDist, newNode});
                    }
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
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while(i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for(int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends