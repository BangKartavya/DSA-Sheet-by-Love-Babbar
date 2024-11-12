//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int transform(string A, string B) {
            int cnt = 0;

            if(A == B) return cnt;

            int n = A.size();
            int m = B.size();

            if(n != m) return -1;

            int freq[256];
            memset(freq, 0, sizeof(freq));

            for(int i = 0; i < n; i++) {
                freq[(int)A[i]]++;
                freq[(int)B[i]]--;
            }

            for(int i = 0; i < 256; i++)
                if(freq[i] != 0) return -1;

            int i = n - 1;
            int j = m - 1;

            while(i >= 0) {
                if(A[i] == B[j]) {
                    i--;
                    j--;
                } else {
                    cnt++;
                    i--;
                }
            }
            return cnt;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.transform(A, B) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends