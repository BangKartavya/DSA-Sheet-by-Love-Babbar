//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        bool isAnagram(string s1, string s2) {
            int freq[26];
            memset(freq, 0, sizeof(freq));

            for(auto i : s1)
                freq[i - 'a']++;
            for(auto i : s2)
                freq[i - 'a']--;

            for(int i = 0; i < 26; i++) {
                if(freq[i] != 0) return false;
            }

            return true;
        }

    public:
        vector<vector<string>> anagrams(vector<string>& arr) {
            vector<vector<string>> ans;
            int n = arr.size();
            unordered_map<string, vector<string>> mp;
            for(int i = 0; i < n; i++) {
                if(mp.empty()) {
                    mp[arr[i]].push_back(arr[i]);
                } else {
                    bool found = false;
                    for(auto& it : mp) {
                        if(isAnagram(it.first, arr[i])) {
                            it.second.push_back(arr[i]);
                            found = true;
                            break;
                        }
                    }

                    if(!found) mp[arr[i]].push_back(arr[i]);
                }
            }

            for(auto it : mp)
                ans.push_back(it.second);

            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while(ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string>> result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[i].size(); j++) {
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