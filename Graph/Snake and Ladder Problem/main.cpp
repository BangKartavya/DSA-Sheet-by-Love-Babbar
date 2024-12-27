//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        int minThrow(int N, int arr[]) {
            int n = 5;
            int m = 6;

            vector<int> adj(n * m, -1);

            for(int i = 0; i < 2 * N; i += 2) {
                adj[arr[i] - 1] = arr[i + 1] - 1;
            }

            vector<bool> vis(n * m, false);
            queue<pair<int, int>> q; // {pos, rolls}
            q.push({0, 0});
            vis[0] = true;

            while(!q.empty()) {
                pair<int, int> top = q.front();
                q.pop();

                if(top.first == n * m - 1) return top.second;

                for(int i = 1; i <= 6; i++) {
                    int newNode = top.first + i;
                    if(newNode >= n * m) break;

                    if(!vis[newNode]) {
                        if(adj[newNode] == -1) {
                            q.push({newNode, top.second + 1});
                        } else {
                            q.push({adj[newNode], top.second + 1});
                        }
                    }
                }
            }

            return -1;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        int arr[2 * N];
        for(int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends