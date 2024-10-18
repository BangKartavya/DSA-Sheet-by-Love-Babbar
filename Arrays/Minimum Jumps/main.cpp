//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
    public:
        int minJumps(vector<int>& arr) {
            int maxReach = 0;
            int lastIdx = 0;
            int jumps = 0;

            int n = arr.size();

            for(int i = 0; i < n; i++) {
                maxReach = max(maxReach, arr[i] + i);
                if(lastIdx == i && i == maxReach && arr[i] == 0) return -1;
                if(lastIdx == i) {
                    jumps++;
                    lastIdx = maxReach;
                }
                if(lastIdx >= n - 1) return jumps;
            }
            return -1;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while(ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends