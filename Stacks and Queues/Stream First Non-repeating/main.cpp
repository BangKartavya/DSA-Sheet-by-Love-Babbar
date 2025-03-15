//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        string FirstNonRepeating(string& S) {
            queue<char> q;
            unordered_map<char, int> mp;
            string result;

            for(char& ch : S) {
                if(mp.find(ch) == mp.end()) {
                    q.push(ch);
                    mp[ch]++;
                    result += q.front();
                }

                else {
                    mp[ch]++;
                    while(!q.empty() && mp[q.front()] > 1) {
                        q.pop();
                    }

                    if(q.empty()) {
                        result += '#';
                    } else result += q.front();
                }
            }

            return result;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends