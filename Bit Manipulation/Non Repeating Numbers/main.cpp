//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int> singleNumber(vector<int>& arr) {
            // sum = (a ^ b) + (a & b) * 2

            int x = 0;

            for(auto i : arr)
                x ^= i;

            x &= -x; // last set bit

            vector<int> ans = {0, 0};

            for(auto i : arr) {
                if((i & x) == 0) ans[0] ^= i;
                else ans[1] ^= i;
            }

            if(ans[0] > ans[1]) swap(ans[0], ans[1]);

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

        Solution ob;
        vector<int> ans = ob.singleNumber(arr);
        for(auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends