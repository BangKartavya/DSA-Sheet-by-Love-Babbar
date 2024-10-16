//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        void segregateElements(vector<int>& arr) {
            vector<int> pos;
            vector<int> neg;

            for(auto i : arr) {
                if(i < 0) neg.push_back(i);
                else pos.push_back(i);
            }

            int i = 0;

            int n = neg.size();
            int m = pos.size();

            for(; i < m; i++) {
                arr[i] = pos[i];
            }
            for(; i < m + n; i++) {
                arr[i] = neg[i - m];
            }
        }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while(t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while(ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for(int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends