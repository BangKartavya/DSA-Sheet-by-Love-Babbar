//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string s, vector<string> &dict) {
        if(s.empty()) return 1;
        
        int siz = s.size();
        
        for(int i = 0;i<=siz;i++) {
            string str = s.substr(0,i);
            if(find(dict.begin(),dict.end(),str) != dict.end() && wordBreak(n,s.substr(i),dict)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends