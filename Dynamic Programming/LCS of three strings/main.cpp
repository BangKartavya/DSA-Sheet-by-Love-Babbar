//{ Driver Code Starts
#include <bits/stdc++.h>

// } Driver Code Ends

class Solution {
    private:
        std::string s1;
        std::string s2;
        std::string s3;

        std::vector<std::vector<std::vector<int>>> dp;

        int solve(int i, int j, int k) {
            if(i < 0 || j < 0 || k < 0) return 0;

            if(dp[i][j][k] != -1) return dp[i][j][k];

            if(s1[i] == s2[j] && s2[j] == s3[k]) return dp[i][j][k] = 1 + solve(i - 1, j - 1, k - 1);

            else {
                int iConst = std::max({solve(i, j - 1, k - 1), solve(i, j - 1, k), solve(i, j, k - 1)});
                int jConst = std::max({solve(i - 1, j, k - 1), solve(i - 1, j, k), solve(i, j, k - 1)});
                int kConst = std::max({solve(i - 1, j - 1, k), solve(i, j - 1, k), solve(i, j - 1, k)});

                return dp[i][j][k] = std::max({iConst, jConst, kConst});
            }
        }

    public:
        int LCSof3(std::string& s1, std::string& s2, std::string& s3) {
            this->s1 = s1;
            this->s2 = s2;
            this->s3 = s3;

            dp.resize(25, std::vector<std::vector<int>>(25, std::vector<int>(25, -1)));

            int l = s1.size();
            int m = s2.size();
            int n = s3.size();
            return solve(l - 1, m - 1, n - 1);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        // int n1, n2, n3; cin >> n1 >> n2 >> n3;
        std::string s1, s2, s3;
        std::cin >> s1 >> s2 >> s3;
        std::cin.ignore();
        Solution obj;
        std::cout << obj.LCSof3(s1, s2, s3) << std::endl;

        std::cout << "~"
                  << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends