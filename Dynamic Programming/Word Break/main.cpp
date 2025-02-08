//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution {
    public:
        int wordBreak(int n, string s, vector<string>& dictionary) {
            vector<bool> dp(s.size() + 1, false);
            dp[s.size()] = true;

            for(int i = s.size() - 1; i >= 0; i--) {
                for(string& word : dictionary) {
                    if(i + word.size() <= s.size()) {
                        string matching = s.substr(i, word.size());
                        if(matching == word) {
                            dp[i] = dp[i + word.size()];
                        }

                        if(dp[i]) break;
                    }
                }
            }

            return dp[0];
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> dictionary;
        for(int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dictionary.push_back(S);
        }
        string s;
        cin >> s;
        Solution ob;
        cout << ob.wordBreak(n, s, dictionary) << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends