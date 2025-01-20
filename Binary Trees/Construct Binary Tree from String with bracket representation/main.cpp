//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
private:
    int i = 0;
    string s;
    int n;
    
    void solve(Node* root) {

        if(i < n && isdigit(s[i])) {
            int num = 0;
            
            while(i < n && isdigit(s[i])) {
                num *= 10;
                num += s[i++]-'0';
            }
            
            root->data = num;
        }
        
        if(i < n && s[i] == '(') {
            root->left = new Node(INT_MIN);
            i++;
            solve(root->left);
            if(root->left->data == INT_MIN) root->left = nullptr;
        }
        
        if(i < n && s[i] == '(') {
            root->right = new Node(INT_MIN);
            i++;
            solve(root->right);
            
            if(root->right->data == INT_MIN) root->right = nullptr;
        }
        
        if(i >= n || s[i] == ')') {
            i++;
            return;
        }
    }
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        Node* root = new Node(INT_MIN);
        n = str.size();
        this->s = str;
        solve(root);
        
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends