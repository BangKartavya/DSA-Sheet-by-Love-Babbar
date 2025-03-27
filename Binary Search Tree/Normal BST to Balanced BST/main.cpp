//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends

/*Structure of the Node of the BST is as
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
        vector<int> elements;
        void inOrder(Node* root) {
            if(!root) return;

            inOrder(root->left);
            elements.push_back(root->data);
            inOrder(root->right);
        }

        Node* buildTree(int s, int e) {
            if(s > e) return nullptr;

            int mid = s + (e - s) / 2;

            Node* root = new Node(elements[mid]);

            root->left = buildTree(s, mid - 1);
            root->right = buildTree(mid + 1, e);

            return root;
        }

    public:
        Node* balanceBST(Node* root) {
            inOrder(root);

            return buildTree(0, elements.size() - 1);
        }
};

//{ Driver Code Starts.

Node* insert(struct Node* node, int key) {
    if(node == NULL)
        return new Node(key);
    if(key < node->data)
        node->left = insert(node->left, key);
    else if(key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node* node) {
    if(node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node* node) {
    if(node == NULL)
        return 0;
    int lDepth = height(node->left);
    int rDepth = height(node->right);
    if(lDepth > rDepth)
        return (lDepth + 1);
    else
        return (rDepth + 1);
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
    Node* root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main() {
    int t;
    cin >> t;
    getchar();
    while(t--) {
        struct Node* root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.balanceBST(root);
        cout << height(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends