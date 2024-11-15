//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    public:
        // arr[] : int input array of integers
        // k : the quadruple sum required
        vector<vector<int>> fourSum(vector<int>& arr, int k) {
            sort(begin(arr), end(arr));
            int n = arr.size();
            set<vector<int>> ans;

            for(int a = 0; a < n; a++) {
                for(int b = a + 1; b < n; b++) {
                    int c = b + 1;
                    int d = n - 1;

                    while(c < d) {
                        if(arr[a] + arr[b] + arr[c] + arr[d] == k) {
                            ans.insert({arr[a], arr[b], arr[c], arr[d]});
                            c++;
                        } else if(arr[a] + arr[b] + arr[c] + arr[d] > k) {
                            d--;
                        } else c++;
                    }
                }
            }
            vector<vector<int>> v(begin(ans), end(ans));
            return v;
        }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while(test_case--) {
        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while(ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(arr, d);
        for(auto& v : ans) {
            for(int& u : v) {
                cout << u << " ";
            }
            cout << endl;
        }
        if(ans.empty()) {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends