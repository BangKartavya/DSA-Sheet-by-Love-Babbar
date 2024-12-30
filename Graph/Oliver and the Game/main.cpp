#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timer = 0;

void dfs(int i, vector<vector<int>>& adj, int par, vector<int>& inTime, vector<int>& outTime) {
    inTime[i] = timer++;

    for(auto it : adj[i]) {
        if(it != par) {
            dfs(it, adj, i, inTime, outTime);
        }
    }
    outTime[i] = timer++;
}

bool solve(int X, int Y, vector<int>& inTime, vector<int>& outTime) {
    return (inTime[X] > inTime[Y] && outTime[X] < outTime[Y]);
}

int main() {
    int n;
    cin >> n;
    timer = 1;
    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < n - 1; i++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    vector<int> inTime(n + 1);
    vector<int> outTime(n + 1);
    dfs(1, adj, 0, inTime, outTime);

    int Q;
    cin >> Q;

    while(Q--) {
        int A, X, Y;
        cin >> A >> X >> Y;

        if(!solve(X, Y, inTime, outTime) && !solve(Y, X, inTime, outTime)) cout << "NO" << endl;
        else {
            if(A == 0) {
                if(solve(Y, X, inTime, outTime)) cout << "YES" << endl;
                else cout << "NO" << endl;
            } else {
                if(solve(X, Y, inTime, outTime)) cout << "YES" << endl;
                else cout << "NO" << endl;
            }
        }
    }

    return 0;
}