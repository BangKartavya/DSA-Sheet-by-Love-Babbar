//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string& s1, string& s2) {
        string con = s1 + s1;
        int n = s1.size();
        int l = 0;
        
        if(n != s2.size()) return false;
        
        for(int i = 0;i<2*n;i++) {
            if(l == s2.size()) break;
            if(con[i] == s2[l]) l++;
        }
        
        return l==s2.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution obj;
        cout << obj.areRotations(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends