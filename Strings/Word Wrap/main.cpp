//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[500][2005];
    
    int solve(int i,int rem,vector<int>& arr,int& k) {
        if(i == arr.size()) return 0;
        
        if(dp[i][rem] != -1) return dp[i][rem];

        int ans = 0;

        if(arr[i] > rem) {
            ans = (rem+1)*(rem+1) + solve(i+1,k-arr[i]-1,arr,k);
        }
        else {
            ans = min((rem+1)*(rem+1) + solve(i+1,k-arr[i]-1,arr,k),solve(i+1,rem-arr[i]-1,arr,k));
        }
        
        return dp[i][rem] = ans;

    }
    
    int solveWordWrap(vector<int>arr, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        
        return solve(0,k,arr,k);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends