//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        vector<vector<int>> dp;
        int n;
        int m;
        string s1;
        string s2;

        int solve(int i, int j) {
            if(i < 0) return j + 1;
            if(j < 0) return i + 1;

            if(dp[i][j] != -1) return dp[i][j];

            if(s1[i] == s2[j]) return solve(i - 1, j - 1);

            else {
                int replace = 1 + solve(i - 1, j - 1);
                int insert = 1 + solve(i, j - 1);
                int del = 1 + solve(i - 1, j);

                return dp[i][j] = min({replace, insert, del});
            }
        }

    public:
        // Function to compute the edit distance between two strings
        int editDistance(string& s1, string& s2) {
            this->s1 = s1;
            this->s2 = s2;

            n = s1.size();
            m = s2.size();

            dp.resize(n, vector<int>(m, -1));

            return solve(n - 1, m - 1);
        }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while(T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends