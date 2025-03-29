//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

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
  public:
    int getCount(Node *root, int l, int h) {
        if(!root) return 0;
        
        if(root->data <= h && root->data >= l) {
            return 1 + getCount(root->left,l,h) + getCount(root->right,l,h);
        }
        
        else if(root->data > h) {
            return getCount(root->left,l,h);
        }
        
        else {
            return getCount(root->right,l,h);
        }
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int l, r;
        cin >> l >> r;
        Solution ob;
        Node* root = buildTree(s);
        cout << ob.getCount(root, l, r) << endl;
        cout << "~"
             << "\n";
    }
    return 1;
}

// } Driver Code Ends