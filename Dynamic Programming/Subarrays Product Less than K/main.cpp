//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        long long countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
            long long int cnt = 0;

            int left = 0;
            int right = 0;

            long long int prod = 1;

            for(; right < n; right++) {
                prod *= arr[right];

                while(left <= right && prod >= k) {
                    prod /= arr[left];
                    left++;
                }

                cnt += (right - left + 1);
            }

            return cnt;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for(i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends