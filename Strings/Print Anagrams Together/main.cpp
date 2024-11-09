//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isAnagram(string& a, string& b) {
        if(a.size() != b.size()) return false;
        
        int chars[26];
        memset(chars,0,sizeof(chars));
        int n = a.size();
        
        for(int i = 0;i<n;i++) {
            chars[a[i]-'a']++;
            chars[b[i]-'a']--;
        }
        
        for(int i =0 ;i<26;i++) if(chars[i] != 0) return false;
        
        return true;
    }
    
    vector<vector<string>> anagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        vector<pair<string,vector<string>>> vp;
        
        for(auto i: arr) {
            if(vp.empty()) {
                vp.push_back({i,{i}});
                continue;
            }
            
            bool pushed = false;
            
            for(auto& it: vp) {
                if(isAnagram(it.first,i)) {
                    it.second.push_back(i);
                    pushed=true;
                }
            }
            
            if(!pushed) vp.push_back({i,{i}});
        }
        
        for(auto it: vp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends