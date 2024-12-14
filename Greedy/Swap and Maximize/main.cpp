//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        long long int ans = 0;
        int n = arr.size();
        vector<int> temp;
        
        sort(begin(arr),end(arr));
        
        for(int i = 0;i<=n/2;i++) {
            if(i == (n-i-1)) {
                temp.push_back(arr[i]);
            }
            else {
                temp.push_back(arr[i]);
                temp.push_back(arr[n-i-1]);
            }
        }

        for(int i = 0;i<n;i++) {
            if(i == n-1) {
                ans += abs(temp[i]-temp[0]);
            }
            else {
                ans += abs(temp[i]-temp[i+1]);
            }
            
            
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends