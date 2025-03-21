//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
    private:
        void heapify(vector<int>& arr, int i, int n) {
            int maxi = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if(l < n && arr[l] > arr[maxi]) {
                maxi = l;
            }
            if(r < n && arr[r] > arr[maxi]) {
                maxi = r;
            }

            if(maxi != i) {
                swap(arr[maxi], arr[i]);
                heapify(arr, maxi, n);
            }
        }

    public:
        void convertMinToMaxHeap(vector<int>& arr, int N) {
            for(int i = N / 2 - 1; i >= 0; i--) {
                heapify(arr, i, N);
            }
        }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--) {
        // Input

        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++)
            cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec, n);
        for(int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;

        // cout << "~\n";

        cout << "~"
             << "\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends