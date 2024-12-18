//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(s > 9*d) return "-1";
        
        string ans;
        
        if(s == 9) {
            if(d == 1) return "9";
            if(d == 2) return "18";
            else {
                ans += '1';
                for(int i = 1;i<d-1;i++) ans += '0';
                ans += '8';
                
                return ans;
                
            }
        }
        
        if(s < 9 && d == 1) return to_string(s);
        
        if(s < 9) {
            ans+= '1';
            d--;
            while(d>0) {
                ans += '0';
                d--;
            }
            ans.back() = to_string(s-1)[0];
            return ans;
        }
        
        for(char dig = '9'; dig >= '0';dig--) {
            while(s-(dig-'0')-1 >= 0 && d > 1) {
                ans = dig + ans;
                s-= (dig-'0');
                d--;
            } 
        }
        
        ans = to_string(s) + ans;
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends