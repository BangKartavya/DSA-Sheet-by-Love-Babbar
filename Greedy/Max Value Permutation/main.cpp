//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    const int MOD = 1e9 + 7; 
  public:
    int maxValue(vector<int> &arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        
        int sum = 0;
        
        for(int i = 0 ;i<n;i++) {
            sum = (sum + (long long)arr[i] * (long long)i)%MOD;
        }
        
        return (sum%MOD);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.maxValue(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends