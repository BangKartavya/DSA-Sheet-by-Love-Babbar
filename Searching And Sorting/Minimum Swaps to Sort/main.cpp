//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        // Function to find the minimum number of swaps required to sort the array.
        int minSwaps(vector<int>& arr) {
            int n = arr.size();

            vector<int> temp = arr;
            map<int, int> mp;

            sort(begin(temp), end(temp));

            for(int i = 0; i < n; i++) {
                mp[arr[i]] = i;
            }

            int ans = 0;

            for(int i = 0; i < n; i++) {
                if(arr[i] != temp[i]) {
                    int init = arr[i];
                    ans++;
                    swap(arr[i], arr[mp[temp[i]]]);

                    mp[init] = mp[temp[i]];
                    mp[temp[i]] = i;
                }
            }

            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends