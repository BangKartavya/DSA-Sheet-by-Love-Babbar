//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMinDiff(vector<int> arr, int m) {
        sort(begin(arr),end(arr));
        
        int n = arr.size();
        
        int mini = INT_MAX;
        
        for(int i = 0;i<n - m + 1;i++) {
            mini = min(arr[i+m-1]-arr[i],mini);
        }
        
        return mini;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int m;
        cin >> m;
        cin.ignore();
        Solution ob;
        cout << ob.findMinDiff(arr, m) << endl;
    }
    return 0;
}
// } Driver Code Ends