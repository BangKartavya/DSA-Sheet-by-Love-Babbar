//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int smallerThan(vector<vector<int>> matrix,int x) {
        int cnt = 0;
        for(auto i: matrix) {
            cnt+=upper_bound(begin(i),end(i),x)-begin(i);
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int n, int m){
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i = 0;i<n;i++) {
            low = min(low,matrix[i][0]);
        }
        for(int i = 0;i<n;i++) {
            high = max(high,matrix[i][m-1]);
        }
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            int smal = smallerThan(matrix,mid);
            
            if(smal <= n*m/2) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends