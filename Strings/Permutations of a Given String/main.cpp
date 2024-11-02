//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        void solve(string& s, string& ds, unordered_set<string>& us, bool freq[]) {
            if(ds.size() == s.size()) {
                us.insert(ds);
                return;
            }

            for(int i = 0; i < s.size(); i++) {
                if(!freq[i]) {
                    freq[i] = true;
                    ds.push_back(s[i]);
                    solve(s, ds, us, freq);
                    ds.pop_back();
                    freq[i] = false;
                }
            }
        }
        vector<string> find_permutation(string s) {
            int n = s.size();
            unordered_set<string> us;
            string ds;
            bool freq[n];

            solve(s, ds, us, freq);

            vector<string> ans;

            for(auto i : us)
                ans.push_back(i);

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends