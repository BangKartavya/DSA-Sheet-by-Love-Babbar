//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>> mp;
        
        for(int i = 0;i<2*e;i+=2) {
            mp[A[i]].push(A[i+1]);
        }
        
        
        for(int i = 0;i<2*e;i+=2) {
            if(mp[B[i]].top() != B[i+1]) return 0;
            
            mp[B[i]].pop();
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends