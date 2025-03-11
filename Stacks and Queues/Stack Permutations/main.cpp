//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> stk;
        vector<int> result;
        
        int n = A.size();
        int i = 0;
        int j = 0;
        
        while(i < n && j < n) {
            stk.push(A[i]);
            
            if(A[i] == B[j]) {
                while(!stk.empty() && B[j] == stk.top()) {
                    stk.pop();
                    j++;
                }
            }
            
            i++;
        }
        
        return stk.empty();
        
    }
};


//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends