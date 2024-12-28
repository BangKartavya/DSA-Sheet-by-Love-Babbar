//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution {
    public:
        string rearrangeString(string str) {
            int n = str.size();
            unordered_map<char, int> mp;

            for(auto i : str)
                mp[i]++;

            priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

            for(auto it : mp) {
                if(it.second > (n + 1) / 2) return "-1";

                pq.push({it.second, it.first});
            }

            string res;

            while(pq.size() >= 2) {
                pair<int, char> a = pq.top();
                pq.pop();
                pair<int, char> b = pq.top();
                pq.pop();

                res += a.second;
                res += b.second;
                a.first--;
                b.first--;

                if(a.first > 0) pq.push(a);
                if(b.first > 0) pq.push(b);
            }

            if(!pq.empty()) res += pq.top().second;

            return res;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        string str1 = ob.rearrangeString(str);
        int flag = 1;
        int c[26] = {0};
        for(int i = 0; i < str.length(); i++)
            c[str[i] - 'a'] += 1;
        int f = 0;
        int x = (str.length() + 1) / 2;
        for(int i = 0; i < 26; i++) {
            if(c[i] > x)
                f = 1;
        }
        if(f) {
            if(str1 == "-1")
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else {
            int a[26] = {0};
            int b[26] = {0};
            for(int i = 0; i < str.length(); i++)
                a[str[i] - 'a'] += 1;
            for(int i = 0; i < str1.length(); i++)
                b[str1[i] - 'a'] += 1;

            for(int i = 0; i < 26; i++)
                if(a[i] != b[i])
                    flag = 0;

            for(int i = 0; i < str1.length(); i++) {
                if(i > 0)
                    if(str1[i - 1] == str1[i])
                        flag = 0;
            }
            if(flag == 1)
                cout << "1\n";
            else
                cout << "0\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends