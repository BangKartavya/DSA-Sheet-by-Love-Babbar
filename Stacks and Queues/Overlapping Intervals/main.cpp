//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
    
        vector<vector<int>> result;
    
        for(int i = 0;i<n;i++) {
            int j = i;
            int k = i+1;
            
            int start = arr[i][0];
            int end = arr[i][1];
            
            while(k < n && arr[i][1] >= arr[k][0]) {
                arr[i][1] = max(end,max(arr[i][1],arr[k][1]));
                k++;
                j++;
            }
            result.push_back({start,arr[i][1]});
            i = j;
        }
    
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends