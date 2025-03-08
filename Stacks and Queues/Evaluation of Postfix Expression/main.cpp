//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        stack<int> stk;
        
        for(string& s: arr) {
            if(s != "+" && s != "-" && s != "*" && s != "/") {
                stk.push(stoi(s));
            }
            
            else {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                
                if(s == "+") {
                    stk.push(a + b);
                }
                
                else if(s == "-") {
                    stk.push(b - a);
                }
                
                else if(s == "*") {
                    stk.push(a * b);
                }
                
                else if(s == "/") {
                    stk.push(b / a);
                }
            }
        }
        
        return stk.top();
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends