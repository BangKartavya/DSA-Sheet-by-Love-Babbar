//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class TrieNode {
    public:
        unordered_map<char,TrieNode*> children;
        char val;
        bool isEnd;
        int freq;
        
        TrieNode(char x) {
            val = x;
            freq = 0;
        }
};

class Trie {
    public:
        TrieNode* root;
        
        Trie() {
            root = new TrieNode(-1);
        }
        
        void add(string s) {
            TrieNode* currNode = root;
            
            for(char& ch: s) {
                if(currNode->children.find(ch) == currNode->children.end()) {
                    currNode->children[ch] = new TrieNode(ch);
                }
                
                currNode = currNode->children[ch];
                currNode->freq++;
            }
            
            currNode->isEnd = true;
        }
        
        string findPrefix(string word) {
            TrieNode* currNode = root;
            
            for(int i = 0;i<word.size();i++) {
                currNode = currNode->children[word[i]];
                
                if(currNode->freq == 1) {
                    return word.substr(0,i+1);
                }
            }
            
            return word;
        }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        Trie* prefixTree = new Trie();
        
        for(int i = 0;i<n;i++) {
            prefixTree->add(arr[i]);
        }
        
        vector<string> result;
        
        for(int i = 0;i<n;i++) {
            result.push_back(prefixTree->findPrefix(arr[i]));
        }
        
        return result;
        
    }
    
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends