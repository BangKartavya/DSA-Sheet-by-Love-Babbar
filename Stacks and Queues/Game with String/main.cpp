//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minValue(string s, int k) {
        priority_queue<int> pq;
        
        unordered_map<char,int> mp;
        
        for(char& ch: s) {
            mp[ch]++;
        }
        
        for(auto& it: mp) pq.push(it.second);
        
        while(!pq.empty()) {
            if(k > 0) {
                int top = pq.top();
                pq.pop();
                pq.push(top-1);
                k--;
            }
            if(k == 0) break;
        }
        
        int ans = 0;
        
        while(!pq.empty()) {
            ans += pq.top() * pq.top();
            pq.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        Solution ob;
        cout << ob.minValue(s, k) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends