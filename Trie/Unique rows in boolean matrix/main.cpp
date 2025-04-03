//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col);

// } Driver Code Ends

class TrieNode {
    public:
        int val;
        bool isEnd;
        unordered_map<int, TrieNode*> children;
        int index;
        TrieNode(int x) {
            val = x;
            isEnd = false;
            index = -1;
        }
};

class Trie {
    private:
    public:
        TrieNode* root;
        vector<vector<int>> result;

        Trie() {
            root = new TrieNode(-1);
        }

        void add(int row[], int n, int idx) {
            TrieNode* currNode = root;

            for(int i = 0; i < n; i++) {
                if(currNode->children.find(row[i]) == currNode->children.end()) {
                    currNode->children[row[i]] = new TrieNode(row[i]);
                }

                currNode = currNode->children[row[i]];
            }

            currNode->isEnd = true;
            if(currNode->index == -1) {
                currNode->index = idx;
                vector<int> r(row, row + n);
                result.push_back(r);
            }
        }
};

class Solution {
    public:
        // #define MAX 1000
        vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col) {
            Trie* prefixTree = new Trie();

            for(int i = 0; i < row; i++) {
                prefixTree->add(M[i], col, i);
            }

            return prefixTree->result;
        }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int a[MAX][MAX];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        Solution ob;
        vector<vector<int>> vec = ob.uniqueRow(a, n, m);
        for(int i = 0; i < vec.size(); i++) {
            for(int x : vec[i]) {
                cout << x << " ";
            }
            cout << "$";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends