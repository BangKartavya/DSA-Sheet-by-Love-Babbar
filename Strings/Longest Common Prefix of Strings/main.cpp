//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        sort(begin(arr),end(arr));
        int n = arr.size();
        if(n == 1) return arr[0];
        int k = arr[0].size();
        string pre;
        
        for(int i =0;i<k;i++) {
            for(int j=0;j<n;j++) {
                if(arr[0][i] != arr[j][i]) {
                    if(pre == "") return "-1";
                    else return pre;
                }
            }
            pre+=arr[0][i];
        }
        return "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends