//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        struct Node* left;
        struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
int kthAncestor(Node* root, int k, int node);

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        int k, node;
        scanf("%d ", &k);
        scanf("%d ", &node);
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        cout << kthAncestor(root, k, node) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends

// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function

int global_Node;

bool findAncestor(Node* root) {
    if(!root) return false;

    if(root->data == global_Node) {
        return true;
    }

    return findAncestor(root->left) || findAncestor(root->right);
}

void dfs(Node* root, stack<Node*>& stk) {
    if(!root) return;

    if(findAncestor(root->left)) {
        stk.push(root);
        dfs(root->left, stk);
    } else if(findAncestor(root->right)) {
        stk.push(root);
        dfs(root->right, stk);
    }
}

int kthAncestor(Node* root, int k, int node) {
    global_Node = node;

    stack<Node*> stk;
    dfs(root, stk);

    if(k > stk.size()) return -1;

    while(k > 0 && !stk.empty()) {
        k--;
        Node* curr = stk.top();

        if(k == 0) return curr->data;

        stk.pop();
    }

    return -1;
}
