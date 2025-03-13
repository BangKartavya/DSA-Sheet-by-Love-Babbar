//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
    public:
        vector<int> rearrangeQueue(queue<int>& q) {
            int n = q.size();
            vector<int> result(n);

            int mid = n / 2;
            int i = 0;

            while(q.size() > mid) {
                result[i] = q.front();
                q.pop();
                i += 2;
            }
            i = 1;
            while(!q.empty()) {
                result[i] = q.front();
                q.pop();
                i += 2;
            }

            return result;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        queue<int> q;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends