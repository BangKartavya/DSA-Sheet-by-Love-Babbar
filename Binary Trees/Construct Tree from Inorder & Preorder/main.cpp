//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node* root) {
    if(root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    private:
        vector<int> preorder;
        vector<int> inorder;
        unordered_map<int, int> mp;
        int n;

        Node* solve(int preS, int preE, int inS, int inE) {
            if(preS > preE || inS > inE) return nullptr;

            Node* root = new Node(preorder[preS]);

            int mid = mp[root->data];

            int numsLeft = mid - inS;

            root->left = solve(preS + 1, preS + numsLeft, inS, mid - 1);
            root->right = solve(preS + numsLeft + 1, preE, mid + 1, inE);

            return root;
        }

    public:
        // Function to build the tree from given inorder and preorder traversals
        Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
            this->preorder = preorder;
            this->inorder = inorder;
            n = inorder.size();

            for(int j = 0; j < n; j++)
                mp[inorder[j]] = j;

            Node* root = solve(0, n - 1, 0, n - 1);

            return root;
        }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while(t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while(ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while(ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node* root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends