//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

struct Node {
        int data;
        struct Node* left;
        struct Node* right;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

void insert(Node** tree, int val) {
    Node* temp = NULL;
    if(!(*tree)) {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node* root, int l, int h) {
    if(!root) return 0;

    if(root->data == h && root->data == l)
        return 1;

    if(root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
            getCountOfNode(root->right, l, h);

    else if(root->data < l)
        return getCountOfNode(root->right, l, h);

    else return getCountOfNode(root->left, l, h);
}

// } Driver Code Ends

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution {
    private:
        unordered_set<int> s;
        bool isDeadEndLeaf(Node* root, int upperBound, int lowerBound) {
            s.insert(root->data);

            if(root->left) {
                if(isDeadEndLeaf(root->left, root->data, lowerBound)) return true;
            }
            if(root->right) {
                if(isDeadEndLeaf(root->right, upperBound, root->data)) return true;
            }
            if(!root->left && !root->right) {
                // for left -> upperbound = root->data
                // for right -> upperbound = upperBound

                // check left

                int j = root->data;
                while(j > lowerBound && s.find(j) != s.end()) {
                    j--;
                }

                if(j != lowerBound) return false;

                // check right
                j = root->data;

                while(j < upperBound && s.find(j) != s.end()) {
                    j++;
                }

                if(j != upperBound) return false;

                return true;
            }

            return false;
        }

    public:
        bool isDeadEnd(Node* root) {
            s.clear();
            return isDeadEndLeaf(root, INT_MAX, 0);
        }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main() {
    int T;
    cin >> T;
    while(T--) {
        Node* root;
        Node* tmp;
        // int i;

        root = NULL;

        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            int k;
            cin >> k;
            insert(&root, k);
        }

        Solution ob;
        cout << ob.isDeadEnd(root);
        cout << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends