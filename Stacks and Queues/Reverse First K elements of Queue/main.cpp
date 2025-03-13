//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
    private:
        int k;
        queue<int> q;

        void solve() {
            if(k <= 0) return;

            int front = q.front();
            q.pop();
            k--;
            solve();

            q.push(front);
        }

    public:
        queue<int> modifyQueue(queue<int> q, int k) {
            this->q = q;
            if(k > q.size()) k = q.size();
            this->k = k;

            int rem = q.size() - k;

            solve();

            while(rem > 0) {
                this->q.push(this->q.front());
                this->q.pop();
                rem--;
            }

            return this->q;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while(n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while(!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends