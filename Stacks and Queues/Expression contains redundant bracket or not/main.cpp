//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    public:
        int checkRedundancy(string s) {
            stack<char> stk;

            for(char& ch : s) {
                if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                    stk.push(ch);
                } else {
                    if(ch == ')') {
                        if(stk.top() == '(') return 1;

                        while(!stk.empty() && stk.top() != '(')
                            stk.pop();
                        stk.pop();
                    }
                }
            }

            return 0;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends