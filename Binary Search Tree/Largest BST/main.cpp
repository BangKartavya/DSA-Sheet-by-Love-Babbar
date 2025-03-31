//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
        int data;
        Node* left;
        Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if(str.length() == 0 || str[0] == 'N') return NULL;

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
        if(i >= ip.size()) break;
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

// } Driver Code Ends

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    private:
        unordered_set<int> s;

        bool check(Node* root, int upperBound, int lowerBound) {
            if(!root) return true;

            if(root->data < upperBound && root->data > lowerBound && s.find(root->data) == s.end()) {
                s.insert(root->data);
                return check(root->left, root->data, lowerBound) && check(root->right, upperBound, root->data);
            }

            return false;
        }

        int size(Node* root) {
            if(!root) return 0;

            return 1 + size(root->left) + size(root->right);
        }

    public:
        int largestBst(Node* root) {
            s.clear();
            if(check(root, INT_MAX, INT_MIN)) {
                return size(root);
            }

            return max(largestBst(root->left), largestBst(root->right));
        }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    scanf("%d ", &t);
    while(t--) {
        string s, ch;
        getline(cin, s);

        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends