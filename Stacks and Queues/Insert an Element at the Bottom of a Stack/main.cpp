//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
    private:
        void insert(stack<int>& stk, int x) {
            if(stk.empty()) {
                stk.push(x);
                return;
            }

            int top = stk.top();
            stk.pop();
            insert(stk, x);
            stk.push(top);
        }

    public:
        stack<int> insertAtBottom(stack<int> stk, int x) {
            insert(stk, x);
            return stk;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        cin >> x;
        stack<int> st;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            st.push(a);
        }
        Solution ob;
        stack<int> tmp = ob.insertAtBottom(st, x);
        vector<int> v;
        while(tmp.size()) {
            v.push_back(tmp.top());
            tmp.pop();
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++) {
            cout << v[i];
            if(i != v.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends