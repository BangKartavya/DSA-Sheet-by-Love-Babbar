//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> adj;
        int v;
        int m;
        vector<int> colour;
        vector<int> vis;

        bool isPossible(int node, int col) {
            for(auto i : adj[node]) {
                if(colour[i] == col) return false;
            }

            return true;
        }

        bool helper(int node) {
            if(node == v) return true;

            for(int i = 1; i <= m; i++) {
                if(isPossible(node, i)) {
                    colour[node] = i;
                    if(helper(node + 1)) return true;
                    colour[node] = 0;
                }
            }

            return false;
        }

    public:
        bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
            this->v = v;
            this->m = m;
            adj.resize(v);

            for(auto i : edges) {
                adj[i.first].push_back(i.second);
                adj[i.second].push_back(i.first);
            }
            colour.resize(v, 0);
            vis.resize(v, false);

            if(helper(0)) return true;

            return false;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for(int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends