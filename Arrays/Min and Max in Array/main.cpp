//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    public:
        pair<long long, long long> getMinMax(vector<long long int> arr) {
            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(auto i : arr) {
                if(i > maxi) maxi = i;
                if(i < mini) mini = i;
            }

            return {mini, maxi};
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends