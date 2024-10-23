//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int> arr) {
        unordered_map<int,int> mp;
        
        int sum = 0;
        int n = arr.size();
        
        for(int i = 0;i<n;i++) {
            if(sum + arr[i] == 0) return true;
            else {
                sum+=arr[i];
                if(mp.find(sum) == mp.end()) mp[sum] = i;
                else return true;
            }
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends