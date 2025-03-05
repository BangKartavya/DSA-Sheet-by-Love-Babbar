//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        bool isBalanced(string& s) {
            stack<char> stk;

            for(char& ch : s) {
                if(ch == '(' || ch == '[' || ch == '{') stk.push(ch);
                else {
                    if(stk.empty()) return false;

                    char c = stk.top();

                    if((c == '(' && ch == ')') ||
                       (c == '[' && ch == ']') ||
                       (c == '{' && ch == '}')) stk.pop();
                    else return false;
                }
            }

            return stk.empty();
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while(t--) {
        cin >> a;
        Solution obj;
        if(obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends