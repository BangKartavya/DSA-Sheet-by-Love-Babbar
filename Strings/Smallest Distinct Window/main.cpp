//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int findSubString(string str) {
            unordered_set<char> s;
            for(auto i : str)
                s.insert(i);

            int sSize = s.size();

            int n = str.size();
            int i = 0;
            int j = s.size();
            int ans = INT_MAX;

            unordered_map<char, int> mp;

            for(int k = i; k < j; k++)
                mp[str[k]]++;

            while(j <= n) {
                if(mp.size() == sSize) {
                    ans = min(ans, j - i);
                    if(mp[str[i]] > 1) {
                        mp[str[i]]--;
                    } else {
                        mp.erase(str[i]);
                    }
                    i++;
                } else {
                    j++;
                    mp[str[j - 1]]++;
                }
            }

            return ans;
        }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends