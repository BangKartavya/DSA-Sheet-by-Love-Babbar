//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        stack<char> stk;
        
        for(auto i: s) {
            if(i == '{' || i == '(' || i == '[') stk.push(i);
            else {
                if(stk.empty()) return false;
                
                if((i == '}' && stk.top() == '{') || (i == ']' && stk.top() == '[') || i == ')' && stk.top() == '(') stk.pop();
                
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
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends