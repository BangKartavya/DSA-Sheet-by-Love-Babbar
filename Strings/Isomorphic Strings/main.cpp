//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution {
    public:
        // Function to check if two strings are isomorphic.
        bool areIsomorphic(string& str1, string& str2) {
            if(str1.size() != str2.size()) return false;

            unordered_map<char, int> mp1;
            unordered_map<char, int> mp2;

            for(auto i : str1)
                mp1[i]++;
            for(auto i : str2)
                mp2[i]++;

            if(mp1.size() != mp2.size()) return false;

            int n = str1.size();

            for(int i = 0; i < n; i++) {
                if(mp1[str1[i]] != mp2[str2[i]]) return false;
            }

            return true;
        }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while(t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if(r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends