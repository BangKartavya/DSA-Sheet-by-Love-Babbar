//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
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

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

int count(Node* root) {
    if(!root) return 0;
    
    return 1 + count(root->left) + count(root->right);
}

void inOrder(Node* root, int& A, int& B, int i , int j, int curr) {
    if(!root) return;
    
    inOrder(root->left,A,B,i,j,curr);
    curr++;
    
    if(curr == i) {
        A = root->data;
    }
    if(curr == j) {
        B = root->data;
    }
    
    inOrder(root->right,A,B,i,j,curr);
}

float findMedian(struct Node *root)
{
    int n = count(root);
    
    int A = -1;
    int B = -1;
    
    cout << "n : " << n << endl;
    
    if(n%2 != 0) {
        
        inOrder(root,A,B,n/2+1,n/2+1,0);
        cout << "A : " << A << endl;
        cout << "B : " << B << endl;
        return (A+B)/2.0;
    }
    else {
        inOrder(root,A,B,n/2,n/2+1,0);
        cout << "A : " << A << endl;
        cout << "B : " << B << endl;
        return (A+B)/2.0;
    }
}

