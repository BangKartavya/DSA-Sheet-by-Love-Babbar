//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
    public:
        bool match(string wild, string pattern) {
            if(wild.size() == 0 && pattern.size() == 0) return true;

            if(wild[0] == '*') {
                int j = 0;
                while(wild[j + 1] == '*')
                    j++;
                wild = wild.substr(j);
            }

            if(wild[0] == '*' && wild.size() > 1 && pattern.size() == 0) return false;

            if(wild[0] == '?' || wild[0] == pattern[0]) return match(wild.substr(1), pattern.substr(1));

            if(wild[0] == '*') return match(wild.substr(1), pattern) || match(wild, pattern.substr(1));

            return false;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        bool x = ob.match(wild, pattern);
        if(x)
            cout << "Yes\n";
        else
            cout << "No\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends