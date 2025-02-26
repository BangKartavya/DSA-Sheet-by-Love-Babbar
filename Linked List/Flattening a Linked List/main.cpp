//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  private:
    Node* merge(Node* head1, Node* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        
        Node* head = new Node(-1);
        Node* temp = head;
        
        while(head1 && head2) {
            if(head1->data <= head2->data) {
                temp->bottom = head1;
                head1 = head1->bottom;
            }
            else {
                temp->bottom = head2;
                head2 = head2->bottom;
            }
            
            temp = temp->bottom;
        }
        
        while(head1) {
            temp->bottom = head1;
            head1 = head1->bottom;
            temp = temp->bottom;
        }
        
        while(head2) {
            temp->bottom = head2;
            head2 = head2->bottom;
            temp = temp->bottom;
        }
        
        return head->bottom;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        
        root->next = flatten(root->next);
        
        return merge(root,root->next);
    }
};



//{ Driver Code Starts.

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
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends