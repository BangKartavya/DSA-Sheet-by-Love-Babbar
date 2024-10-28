//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> Mat) {
        vector<int> v;
        
        for(auto i: Mat) for(auto j: i) v.push_back(j);
        
        sort(begin(v),end(v));
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        int i = 0;
        int j = 0;
        
        for(int k = 0;k<n*n;k++) {
            if(j == n) {
                i++;
                j = 0;
            }
            ans[i][j++] = v[k];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    
cout << "~" << "\n";
}
}
// } Driver Code Ends