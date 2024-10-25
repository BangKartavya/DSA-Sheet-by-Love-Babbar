//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int total = accumulate(begin(arr),end(arr),0);
        
        if(x > total) return 0;
        if(x == total) return arr.size();
        
        int mini = INT_MAX;
        
        int n = arr.size();
        int start = 0;
        int end = 0;
        
        int currSum = 0;
        
        while(end < n) {
            
            
            while(currSum <= x && end < n) {
                currSum += arr[end++];
            }
            
            while(currSum > x && start < end) {
                mini = min(end-start,mini);
                currSum -= arr[start++];
            }
        }
        
        return mini;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << "\n~\n";
    }

    return 0;
}
// } Driver Code Ends