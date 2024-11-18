//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int countBits(int n) {
    int ans = 0;
    while(n) {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}

bool cmp(const int& a, const int& b) {
    return countBits(a) > countBits(b);
}

class Solution {
    public:
        void sortBySetBitCount(int arr[], int n) {
            stable_sort(arr, arr + n, cmp);

            return;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends