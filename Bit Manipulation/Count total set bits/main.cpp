//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        int max_pow_2(int n) {
            int cnt = 0;

            while((1 << cnt) <= n)
                cnt++;

            return cnt - 1;
        }

    public:
        int countSetBits(int n) {
            if(n == 0) return 0;

            int x = max_pow_2(n);
            int y = x * 1 << (x - 1);
            int z = n - (1 << (x));

            return z + y + countSetBits(z) + 1;
        }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;  // input testcases
    while(t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends