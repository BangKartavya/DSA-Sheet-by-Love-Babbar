//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    int chars[26];
    
    memset(chars,-1,sizeof(chars));
    string ans;
    for(auto i: s) {
        if(chars[i-'a'] != -1) return ans+=i;
        else chars[i-'a'] = 1;
    }
    return "-1";
}