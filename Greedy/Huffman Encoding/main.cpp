//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node {
    public:
    
        Node* left = nullptr;
        Node* right = nullptr;
        int data;
    
        Node(int data) {
            this->data = data;
        }
};

struct cmp {
    bool operator()( const Node* a, const Node* b ) const {
        return a->data > b->data;
   }
};

class Solution {
    private:
        vector<string> ans;
	    unordered_map<int,char> mp;
        
        void preOrder(Node* root,string s) {
            if(!root->left && !root->right) {
                ans.push_back(s);
                return;
            }
            else {
                preOrder(root->left,s+'0');
                preOrder(root->right,s+'1');
            }
        }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*,vector<Node*>, cmp> pq;
		    
		    for(auto i: f) {
		        pq.push(new Node(i));
		    }
		    

		    for(int i = 0;i<N;i++) {
		        mp[f[i]] = S[i];
		    }
    		    
	        while(pq.size() != 1) {
	            Node* a = pq.top();
	            pq.pop();
	            Node* b = pq.top();
	            pq.pop();
	            
	            Node* root = new Node(a->data+b->data);
	            root->left = a;
	            root->right = b;
	            
	            pq.push(root);
	            
	        }	
	        
	        preOrder(pq.top(),"");
	        return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends