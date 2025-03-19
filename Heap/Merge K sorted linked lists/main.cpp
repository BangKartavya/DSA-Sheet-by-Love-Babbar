//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends

/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  private:
    Node* merge(Node* a, Node* b) {
        Node* temp1 = a;
        Node* temp2 = b;
        
        Node* result = new Node(-1);
        Node* temp3 = result;
    
        while(temp1 && temp2) {
            if(temp1->data < temp2->data) {
                temp3->next = temp1;
                temp1 = temp1->next;
            }
            else{
              temp3->next = temp2;
              temp2 = temp2->next;
            } 
            
            temp3 = temp3->next;
        }
        
        while(temp1) {
            temp3->next = temp1;;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        
        while(temp2) {
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        return result->next;
    }
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        Node* result = arr[0];
        
        for(int i = 1;i<arr.size();i++) {
            result = merge(result,arr[i]);
        }
        
        return result;
    }
};



//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends