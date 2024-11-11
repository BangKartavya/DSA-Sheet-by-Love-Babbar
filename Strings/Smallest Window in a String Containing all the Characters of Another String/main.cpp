//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find the smallest window in the string s1 consisting
        // of all the characters of string s2.

        bool match(unordered_map<char, int>& vis, unordered_map<char, int>& pat) {
            if(vis.size() < pat.size()) return false;

            for(auto it : pat) {
                if(vis.find(it.first) == vis.end() || vis[it.first] < it.second) return false;
            }

            return true;
        }

        string smallestWindow(string& s1, string& s2) {
            unordered_map<char, int> pat;
            unordered_map<char, int> vis;

            int n = s1.size();

            for(auto i : s2)
                pat[i]++;

            int i = 0;
            int j = 0;

            int start = -1;
            int end = -1;
            int length = INT_MAX;

            while(j <= n) {
                if(!match(vis, pat)) {
                    j++;
                    vis[s1[j - 1]]++;
                } else {
                    if(j - i < length) {
                        start = i;
                        end = j;
                        length = j - i;
                    }

                    if(vis[s1[i]] > 1) vis[s1[i]]--;
                    else vis.erase(s1[i]);
                    i++;
                }
            }

            if(start == -1 && end == -1) {
                if(match(vis, pat)) return s1;
                else return "-1";
            }

            string res;
            for(int k = start; k < end; k++)
                res += s1[k];

            return res;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        cout << obj.smallestWindow(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends