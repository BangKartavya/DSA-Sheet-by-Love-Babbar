//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int inSequence(int a, int b, int c) {
    
        int s = 0;
        int e = b/c+1;
        
        while(s <= e) {
            int mid = s + (e-s)/2;
            
            if(a + mid*c == b) return true;
            
            else if(a + mid*c < b) s = mid+1;
            
            else e = mid-1;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int A, B, C;
        cin >> A >> B >> C;

        Solution ob;
        int ans = ob.inSequence(A, B, C);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends