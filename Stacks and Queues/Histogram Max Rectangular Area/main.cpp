//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        int getMaxArea(vector<int>& arr) {
            stack<int> stk;
            int n = arr.size();
            int maxi = 0;

            for(int i = 0; i < n; i++) {
                while(!stk.empty() && arr[i] < arr[stk.top()]) {
                    int elem = stk.top();
                    stk.pop();
                    int nextSmall = i;
                    int prevSmall = stk.empty() ? -1 : stk.top();

                    cout << "nextSmall : " << nextSmall << endl;
                    cout << "prevSmall : " << prevSmall << endl;
                    cout << "elem : " << elem << endl;
                    cout <

                        int maxi = max(maxi, arr[elem] * (nextSmall - prevSmall - 1));
                }
                stk.push(i);
            }

            while(!stk.empty()) {
                int elem = stk.top();
                stk.pop();
                int nextSmall = n;
                int prevSmall = stk.empty() ? -1 : stk.top();

                int maxi = max(maxi, arr[elem] * (nextSmall - prevSmall - 1));
            }

            return maxi;
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Endsm