//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int maxi = INT_MIN;
        
        for(int i = 0;i<n;i++) {
            vector<int> tempRow(m);
            for(int j = i;j<n;j++) {
                for(int c = 0;c<m;c++) {
                    tempRow[c] += mat[j][c];
                }
                int sum = 0;
                
                for(int c = 0;c<m;c++) {
                    sum += tempRow[c];
                    if(sum > maxi) {
                        maxi = sum;
                    }
                    if(sum < 0) sum = 0;
                }
            }
            
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(v) << "\n";
    }
}
// } Driver Code Ends