//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        vector<int> result;
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = arr.size();
        
        for(int i = 0;i<k;i++) {
            pq.push(arr[i]);
        }
        
        for(int i = k;i<n;i++) {
            if(pq.top() < arr[i]) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        
        reverse(begin(result),end(result));
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends