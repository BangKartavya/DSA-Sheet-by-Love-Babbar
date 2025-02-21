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

void printList(Node* node) {
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
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
        void merge(Node* head, int s, int mid, int e) {
            int n1 = mid - s + 1;
            int n2 = e - mid;

            vector<int> L(n1);
            vector<int> R(n2);

            Node* temp = head;
            int cnt = 0;

            while(cnt < s) {
                cnt++;
                temp = temp->next;
            }

            for(int i = 0; i < n1; i++) {
                L[i] = temp->data;
                temp = temp->next;
            }
            temp = head;
            cnt = 0;

            while(cnt <= mid) {
                cnt++;
                temp = temp->next;
            }

            for(int i = 0; i < n2; i++) {
                R[i] = temp->data;
                temp = temp->next;
            }

            // merge

            int i = 0;
            int j = 0;

            temp = head;
            cnt = 0;
            while(cnt < s) {
                cnt++;
                temp = temp->next;
            }

            while(i < n1 && j < n2) {
                if(L[i] <= R[j]) {
                    temp->data = L[i];
                    temp = temp->next;
                    i++;
                } else {
                    temp->data = R[j];
                    temp = temp->next;
                    j++;
                }
            }

            while(i < n1) {
                temp->data = L[i++];
                temp = temp->next;
            }

            while(j < n2) {
                temp->data = R[j++];
                temp = temp->next;
            }
        }

        void mergeSort(Node* head, int s, int e) {
            if(s >= e) return;

            if(s < e) {
                int mid = s + (e - s) / 2;

                mergeSort(head, s, mid);
                mergeSort(head, mid + 1, e);
                merge(head, s, mid, e);
            }
        }

    public:
        // Function to sort the given linked list using Merge Sort.
        Node* mergeSort(Node* head) {
            if(!head || !head->next) return head;
            Node* temp = head;

            int e = 0;
            while(temp) {
                temp = temp->next;
                e++;
            }

            mergeSort(head, 0, e - 1);

            return head;
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

        // Read numbers from the input line
        while(ss >> number) {
            arr.push_back(number);
        }
        Node* head = nullptr;
        // Check if the array is empty
        if(!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for(size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node* ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends