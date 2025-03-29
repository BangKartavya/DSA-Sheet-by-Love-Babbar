//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Back-end complete function Template for C++

class Node {
    public:
        Node* left;
        Node* right;
        int data;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    private:
        Node* insertIntoBST(Node* root, int val, int& suc) {
            if(!root) return new Node(val);

            if(val >= root->data) {
                root->right = insertIntoBST(root->right, val, suc);
            }

            else {
                suc = root->data;
                root->left = insertIntoBST(root->left, val, suc);
            }

            return root;
        }

    public:
        vector<int> findLeastGreater(vector<int>& arr, int n) {
            vector<int> result(n);
            Node* root = nullptr;

            for(int i = n - 1; i >= 0; i--) {
                int suc = -1;
                root = insertIntoBST(root, arr[i], suc);
                result[i] = suc;
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
        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends