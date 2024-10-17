//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    public:
        int getMinDiff(vector<int>& arr, int k) {
            sort(begin(arr), end(arr));

            int n = arr.size();

            int mi = arr[0];
            int ma = arr[n - 1];

            int ans = ma - mi;

            int new_min = mi + k;
            int new_max = ma - k;

            for(int i = 0; i < n - 1; i++) {
                int smallest = min(new_min, arr[i + 1] - k);
                int largest = max(new_max, arr[i] + k);
                if(smallest < 0) continue;

                ans = min(ans, largest - smallest);
            }

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while(ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends