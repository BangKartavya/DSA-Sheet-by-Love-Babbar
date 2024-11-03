//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int countRev(string s);
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev(string s) {
    int n = s.size();

    if(n % 2) return -1;

    stack<char> stk;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '{') stk.push('{');
        else {
            if(stk.empty()) {
                cnt++;
                stk.push('{');
            } else {
                stk.pop();
            }
        }
    }

    if(stk.empty()) return cnt;
    else return cnt += stk.size() / 2;
}