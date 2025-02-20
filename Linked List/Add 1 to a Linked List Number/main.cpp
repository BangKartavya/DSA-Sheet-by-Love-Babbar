//{ Driver Code Starts
// Initial template for C++

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

void printList(Node* node) {
    while(node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    private:
        Node* reverseList(Node* head) {
            if(!head || !head->next) return head;

            Node* prev = nullptr;
            Node* curr = head;

            while(curr) {
                Node* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            return prev;
        }

    public:
        Node* addOne(Node* head) {
            Node* one = new Node(1);

            if(!head) return one;

            Node* revHead = reverseList(head);
            Node* temp = revHead;

            int carry = 0;

            while(temp && one) {
                int sum = temp->data + one->data;

                if(sum == 10) {
                    temp->data = 0;
                    carry = 1;
                } else {
                    temp->data = sum;
                }

                temp = temp->next;
                one = one->next;
            }

            while(carry && temp && temp->next) {
                int sum = temp->data + carry;

                if(sum == 10) {
                    temp->data = 0;
                    carry = 1;
                } else {
                    temp->data = sum;
                    carry = 0;
                }
                temp = temp->next;
            }
            Node* ans = reverseList(revHead);

            if(!temp) {
                if(!carry) return ans;

                else {
                    one = new Node(1);
                    one->next = ans;

                    return one;
                }
            }

            temp->data = (temp->data + carry == 10) ? 0 : temp->data + carry;

            if(carry) {
                one = new Node(1);
                one->next = ans;
            }

            return carry ? one : ans;
        }
};

//{ Driver Code Starts.

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
        while(ss >> number) {
            arr.push_back(number);
        }

        if(arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for(int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends