//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  private:
    vector<int> result;
    unordered_set<int> s;
    Node* rightMostLeaf;
    Node* leftMostLeaf = NULL;
    bool stop = false;
    
    
    void dfs(Node* root) {
        if(!root) return;
        
        if(!root->left && !root->right) {
            if(leftMostLeaf == NULL) leftMostLeaf = root;
            rightMostLeaf = root;
        }
        
        dfs(root->left);
        dfs(root->right);
    }
    
    
    void leftBoundary(Node* root,vector<int> path) {
        if(!root) return;
        
        if(root == leftMostLeaf) {
            for(int& i: path) {
                result.push_back(i);
            }
            stop = true;
            return;
        }
        
         if(s.find(root->data) == s.end()) {
            path.push_back(root->data);
            s.insert(root->data);
        }
        if(!stop) {
            leftBoundary(root->left,path);
        }
        if(!stop) {
            leftBoundary(root->right,path);
        }
        
        return;
    }
    
    void leafNodes(Node* root) {
    
        if(!root) return;
        
        if(!root->left && !root->right) {
            if(s.find(root->data) == s.end()) {
                result.push_back(root->data);
                s.insert(root->data);
                return;
            }
        }
        
        leafNodes(root->left);
        leafNodes(root->right);
        
    }
    
    void rightBoundary(Node* root,stack<int> stk) {
        if(!root) return;
        
        if(root == rightMostLeaf) {
            while(!stk.empty()) {
                result.push_back(stk.top());
                stk.pop();
            }
            stop = true;
            return;
        }
        
        if(s.find(root->data) == s.end()) {
            stk.push(root->data);
            s.insert(root->data);
        }
        if(!stop) {
            rightBoundary(root->right, stk);
        }
        if(!stop) {
            rightBoundary(root->left, stk);
        }
    }
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        if(!root) return result;
        dfs(root);
        
        result.push_back(root->data);
        s.insert(root->data);
        leftBoundary(root->left,vector<int>());
        
        stop = false;
        leafNodes(root);
        rightBoundary(root->right,stack<int>());
        
        return result;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends