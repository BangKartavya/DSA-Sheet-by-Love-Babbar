//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    private:
    int* keys;
    int* freq;
    int n;
    vector<int> pref;
    vector<vector<int>> dp;
    
    int solve(int i, int j) {
        if(i >= n || j < i) return 0;
        
        if(i == j) return freq[i];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int res = INT_MAX;
        int sum =  pref[j] - (i > 0 ? pref[i-1] : 0);
        
        for(int k = i;k<=j;k++) {
            int leftSubTree = solve(i,k-1);
            int rightSubTree = solve(k+1,j);
            
            res = min(res,leftSubTree + rightSubTree + sum);
        }
        
        return dp[i][j] = res;
    }
    
    public:
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        this->keys = keys;
        this->freq = freq;
        this->n = n;
        
        pref.resize(n);
        dp.resize(n+1,vector<int>(n+1,-1));
        
        for(int i = 0;i<n;i++) {
            pref[i] = freq[i] + (i > 0 ? pref[i-1] : 0);
        }
        
        return solve(0,n-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends