//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    public:
        int middle(int A, int B, int C) {
            // code here//Position this line where user code will be pasted.

            if((A > B && A < C) || (A > C && A < B)) return A;
            if((B > A && B < C) || (B > C && B < A)) return B;
            if((C > A && C < B) || (C > B && C < A)) return C;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends