//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int fav = 0;
        int non_fav = 0;
        int res = INT_MAX;
        
        for(int i = 0;i<n;i++) if(arr[i] <= k) fav++;
        for(int i =0 ;i<fav;i++) if(arr[i] > k) non_fav++;
        
        int l = 0;
        int r = fav-1;
        
        while(r < n) {
            res = min(res,non_fav);
            
            r++;
            if(r < n && arr[r] > k) non_fav++;
            if(l < n && arr[l] > k) non_fav--;
            l++;
        }
        
        return res == INT_MAX ? 0 : res;
        
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends