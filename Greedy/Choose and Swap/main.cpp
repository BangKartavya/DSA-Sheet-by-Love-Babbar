//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string chooseandswap(string str) {
        map<char,int> mp;
        int n = str.size();
        
        for(auto i: str) mp[i]++;
        
        int i = 0;
        
        char to_replace = str[i];
        char with = mp.begin()->first;
        mp.erase(with);
        i++;
     
        while(to_replace <= with) {
            to_replace = str[i];
            with = mp.begin()->first;
            
            if(mp.find(to_replace) == mp.end()) {
                i++;
                continue;
            }
            
            mp.erase(with);
            i++;
        }
        
        if(!with) return str;
        
        
        
        for(int i = 0;i<n;i++) {
            if(str[i] == to_replace) {
                str[i] = with;
            }
            else if(str[i] == with) {
                str[i] = to_replace;
            }
        }
        
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends