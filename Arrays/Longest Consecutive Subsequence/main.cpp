//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(vector<int>& arr) {
        int maxi = 0;
        unordered_set<int> s(begin(arr),end(arr));
        
        int n = arr.size();
        
        for(int i = 0;i<n;i++) {
            if(s.find(arr[i]-1) == s.end()) {
                int key = arr[i];
                int len = 1;
                while(s.find(key+1) != s.end()) {
                    len++;
                    key++;
                }
                
                maxi = max(maxi,len);
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.findLongestConseqSubseq(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends