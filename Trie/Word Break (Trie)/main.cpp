//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class TrieNode {
    public:
        char val;
        int freq;
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode(char x) {
            val = x;
            freq = 0;
            isEnd = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode(-1);
        }

        void add(const string& s) {
            TrieNode* currNode = root;

            for(const char& ch : s) {
                if(currNode->children.find(ch) == currNode->children.end()) {
                    currNode->children[ch] = new TrieNode(ch);
                }

                currNode = currNode->children[ch];
                currNode->freq++;
            }
            currNode->isEnd = true;
        }

        bool find(string s) {
            TrieNode* currNode = root;

            for(char& ch : s) {
                if(currNode->children.find(ch) == currNode->children.end()) return false;

                currNode = currNode->children[ch];
            }

            return currNode->isEnd;
        }
};

class Solution {
    private:
        Trie* prefixTree;
        string A;

        vector<vector<int>> dp;

        bool solve(int i, int j) {
            if(i > j) return false;

            if(prefixTree->find(A.substr(i, j - i + 1))) return true;

            if(dp[i][j] != -1) return dp[i][j];

            for(int k = 0; k < j; k++) {
                if(solve(i, k) && solve(k + 1, j)) return dp[i][j] = true;
            }

            return dp[i][j] = false;
        }

    public:
        int wordBreak(string A, vector<string>& B) {
            prefixTree = new Trie();
            for(string& s : B) {
                prefixTree->add(s);
            }
            dp.resize(A.size(), vector<int>(A.size(), -1));
            this->A = A;
            return solve(0, A.size() - 1);
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> dict;
        for(int i = 0; i < n; i++) {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        Solution ob;
        cout << ob.wordBreak(line, dict) << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends