//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        struct Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
};

// } Driver Code Ends
/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
    public:
        pair<Node*, Node*> splitList(struct Node* head) {
            Node* slow = head;
            Node* fast = head;

            while(fast && fast->next != head) {
                slow = slow->next;
                fast = fast->next->next;

                if(slow == fast) {
                    slow = head;
                    fast = head;

                    while(fast && fast->next->next != head) {
                        slow = slow->next;
                        fast = fast->next->next;
                    }

                    Node* head1 = head;
                    Node* head2 = slow->next;

                    Node* temp = slow->next;

                    while(temp->next != head)
                        temp = temp->next;

                    temp->next = slow->next;
                    slow->next = head;

                    return {head1, head2};
                }
            }
            Node* head2 = slow->next;
            Node* head1 = head;
            slow->next = head;
            fast->next = head2;

            return {head1, head2};
        }
};

//{ Driver Code Starts.

void printList(struct Node* head) {
    struct Node* temp = head;
    if(head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
        printf("\n");
    }
}

struct Node* newNode(int key) {
    struct Node* temp = new Node(key);

    return temp;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while(ss >> number) {
            arr.push_back(number);
        }
        struct Node *temp, *head = NULL;

        // Check if the array is empty
        if(!arr.empty()) {
            head = new Node(arr[0]);
            temp = head;
            for(size_t i = 1; i < arr.size(); ++i) {
                temp->next = new Node(arr[i]);
                temp = temp->next;
            }
        }
        temp->next = head;
        Solution ob;
        auto result = ob.splitList(head);
        struct Node* head1 = result.first;
        struct Node* head2 = result.second;
        printList(head1);
        printList(head2);
    }

    return 0;
}

// } Driver Code Ends