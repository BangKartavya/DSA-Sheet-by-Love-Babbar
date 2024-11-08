//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    bool check(string s) {
        int n = s.size();
        if(n<=0 || n>3) return false;
        if(s[0] == '0' && n > 1) return false;
        if(stoi(s) > 255) return false;
        
        return true;
    }
    string gen(string& s,int n,int i,int j,int k) {
        string p1 = s.substr(0,i+1);
        string p2 = s.substr(i+1,j-i);
        string p3 = s.substr(j+1,k-j);
        string p4 = s.substr(k+1,n-k-1);
        
        if(check(p1) && check(p2) && check(p3) && check(p4)) 
            return p1 + '.' + p2 + '.' + p3 + '.' + p4;
        
        return "";
    }
    vector<string> genIp(string &s) {
        vector<string> ans;
        int n = s.size();
        
        for(int i = 0;i<n;i++) {
            for(int j = i+1;j<n;j++) {
                for(int k = j+1;k<n;k++) {
                    string ip = gen(s,n,i,j,k);
                    if(ip != "") ans.push_back(ip);
                }
            }
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    
cout << "~" << "\n";
}
}
// } Driver Code Ends