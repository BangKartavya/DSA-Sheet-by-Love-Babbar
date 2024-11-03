//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> ans;
            int n = text.size();
            int m = pattern.size();
            for(int i =0 ;i<n;i++) {
                int j;
                for(j = 0;j<m;j++) if(text[j+i] != pattern[j]) break;
                
                if(j == m) ans.push_back(i+1);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends