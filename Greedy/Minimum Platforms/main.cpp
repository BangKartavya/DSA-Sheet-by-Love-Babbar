//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        // Function to find the minimum number of platforms required at the
        // railway station such that no train waits.
        int findPlatform(vector<int>& arr, vector<int>& dep) {
            int n = arr.size();

            int max_dep = *max_element(begin(dep), end(dep));

            vector<int> v(max_dep + 2);

            for(int i = 0; i < n; i++) {
                v[arr[i]]++;
                v[dep[i] + 1]--;
            }

            int res = 0;
            int cnt = 0;
            for(int i = 0; i < max_dep + 2; i++) {
                cnt += v[i];
                res = max(res, cnt);
            }

            return res;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while(ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends