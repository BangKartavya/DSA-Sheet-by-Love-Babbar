//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// design the class in the most optimal way

struct DLLNode {
    DLLNode* next = nullptr;
    DLLNode* prev = nullptr;
    int key = -1;
    int value = -1;
};

class LRUCache {
  private:
    DLLNode* head;
    DLLNode* tail;
    unordered_map<int,DLLNode*> mp; // {key, node}
    int cap;
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        this->cap = cap;
        head = new DLLNode();
        tail = new DLLNode();
        
        head->next = tail;
        tail->prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        DLLNode* node = mp[key];
        
        int value = node->value;
        
        DLLNode* temp = node->next;
            
        temp->prev = node->prev;
        node->prev->next = temp;
        
        temp = head->next;
     
        head->next = node;
        node->prev = head;
        
        node->next = temp;
        temp->prev = node;
        
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        
        if(mp.size() == cap && mp.find(key) == mp.end()) {
            DLLNode* rem = tail->prev;
            
            tail->prev = rem->prev;
            rem->prev->next = tail;
            mp.erase(rem->key);
        }
        
        if(mp.find(key) == mp.end()) {
            // insert
            DLLNode* node = new DLLNode();
            node->key = key;
            node->value = value;
            mp[key] = node;
            
            DLLNode* temp = head->next;
         
            head->next = node;
            node->prev = head;
            
            node->next = temp;
            temp->prev = node;
            return;
        }
        else {
            
            DLLNode* node = mp[key];
            node->value = value;
            
            DLLNode* temp = node->next;
            
            temp->prev = node->prev;
            node->prev->next = temp;
            
            temp = head->next;
         
            head->next = node;
            node->prev = head;
            
            node->next = temp;
            temp->prev = node;
            
            return;
        }
    }
        
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends