//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int minFlips (string s)
{
    int n = s.size();
    int a1 = 0;
    int a2 = 0;
    
    for(int i =0;i<n;i++) {
        if(i%2 == 0) {
            a1 += (s[i] != '0');
            a2 += (s[i] != '1');
        }
        else {
            a1 += (s[i] != '1');
            a2 += (s[i] != '0');
        }
    }
    
    return min(a1,a2);
}