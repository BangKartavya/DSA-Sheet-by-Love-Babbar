//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class TrieNode {
    public:
        char val;
        bool isEnd;
        map<char, TrieNode*> children;

        TrieNode(char x) {
            val = x;
            isEnd = false;
        }
};

class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode(-1);
        }

        void add(string s) {
            TrieNode* currNode = root;

            for(char& ch : s) {
                if(currNode->children.find(ch) == currNode->children.end()) {
                    currNode->children[ch] = new TrieNode(ch);
                }

                currNode = currNode->children[ch];
            }

            currNode->isEnd = true;
        }

        void createString(TrieNode* currNode, vector<string>& ans, string prefix) {
            if(currNode->isEnd) {
                ans.push_back(prefix);
            }

            for(auto it : currNode->children) {
                createString(it.second, ans, prefix + it.first);
            }

            return;
        }

        vector<string> startsWith(string prefix) {
            TrieNode* currNode = root;

            for(char& ch : prefix) {
                if(currNode->children.find(ch) == currNode->children.end()) return {"0"};

                currNode = currNode->children[ch];
            }

            vector<string> result;

            createString(currNode, result, prefix);
            return result;
        }
};

class Solution {
    public:
        vector<vector<string>> displayContacts(int n, string contact[], string s) {
            Trie* prefixTree = new Trie();

            for(int i = 0; i < n; i++) {
                prefixTree->add(contact[i]);
            }

            vector<vector<string>> result;
            string prefix;

            for(int i = 0; i < s.size(); i++) {
                prefix += s[i];
                result.push_back(prefixTree->startsWith(prefix));
            }

            return result;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string contact[n], s;
        for(int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0; i < ans.size(); i++) {
            for(auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends