//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        
        sort(arr,arr+n);
        
        for(int i =0 ;i<n;i++) {
            int j = i+1;
            int k = n-1;
            
            int rem = x - arr[i];
            
            while(j < k) {
                if(arr[j] + arr[k] == rem) return true;
                else if(arr[j] + arr[k] < rem) j++;
                else k--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends