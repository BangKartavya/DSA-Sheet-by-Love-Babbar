//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int total = n*m;
        
        vector<int> ans;
        
        int up_wall = 0;
        int right_wall = m-1;
        int down_wall = n-1;
        int left_wall = 0;
        
        while(ans.size() < total) {
            for(int j =left_wall ;j<=right_wall;j++) {
                if(ans.size() == total) break;
                ans.push_back(mat[up_wall][j]);
            }
            up_wall++;
            
            for(int i =up_wall;i <= down_wall;i++) {
                if(ans.size() == total) break;
                ans.push_back(mat[i][right_wall]);
            }
            right_wall--;

            for(int j = right_wall; j>=left_wall;j--) {
                if(ans.size() == total) break;
                ans.push_back(mat[down_wall][j]);
            }
            down_wall--;
            
            for(int i = down_wall;i>=up_wall;i--) {
                if(ans.size() == total) break;
                ans.push_back(mat[i][left_wall]);
            }
            left_wall++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends