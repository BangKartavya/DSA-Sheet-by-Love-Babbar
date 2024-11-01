//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        if(n == 1) return "1";
        
        string prev = lookandsay(n-1);
        
        string ans = "";
        
        int cnt = 0;
        int sz = prev.size();
        for(size_t i = 0;i<sz;i++) {
            cnt++;
            
            if(i == sz-1 || prev[i] != prev[i+1]) {
                ans += to_string(cnt) + prev[i];
                cnt = 0;
            }
        }
        
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends