//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
        int data;
        struct Node* next;

        Node(int x) {
            data = x;
            next = NULL;
        }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while(ss >> number) {
        arr.push_back(number);
    }
    if(arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for(int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while(n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
        Node* reverseList(Node* head) {
            if(!head || !head->next) return head;

            Node* curr = head;
            Node* prev = nullptr;

            while(curr) {
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

    public:
        Node* addTwoLists(Node* num1, Node* num2) {
            while(num1 && num1->data == 0)
                num1 = num1->next;
            while(num2 && num2->data == 0)
                num2 = num2->next;

            Node* revNum1 = reverseList(num1);
            Node* revNum2 = reverseList(num2);

            Node* tempNum1 = revNum1;
            Node* tempNum2 = revNum2;

            int carry = 0;

            Node* dummy = new Node(-1);
            Node* temp = dummy;

            while(tempNum1 && tempNum2) {
                temp->next = new Node(tempNum1->data + tempNum2->data + carry);

                if(temp->next->data >= 10) {
                    carry = temp->next->data / 10;
                    temp->next->data %= 10;
                } else carry = 0;
                tempNum1 = tempNum1->next;
                tempNum2 = tempNum2->next;
                temp = temp->next;
            }

            while(tempNum1) {
                temp->next = new Node(tempNum1->data + carry);

                if(temp->next->data >= 10) {
                    carry = temp->next->data / 10;
                    temp->next->data %= 10;
                } else carry = 0;
                tempNum1 = tempNum1->next;
                temp = temp->next;
            }
            while(tempNum2) {
                temp->next = new Node(tempNum2->data + carry);

                if(temp->next->data >= 10) {
                    carry = temp->next->data / 10;
                    temp->next->data %= 10;
                } else carry = 0;
                tempNum2 = tempNum2->next;
                temp = temp->next;
            }

            Node* ans = reverseList(dummy->next);

            if(carry) {
                Node* c = new Node(carry);
                c->next = ans;
                return c;
            }

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while(t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends