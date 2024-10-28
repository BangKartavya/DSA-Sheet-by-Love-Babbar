//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int n = array1.size();
        int m = array2.size();
        
        if(n > m) {
            return MedianOfArrays(array2,array1);
        }
        int left = (n+m+1)/2;
        int low = 0;
        int high = n;
        
        
        while(low <= high) {
            int mid1 = low + (high-low)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            
            
            if(mid1 < n) r1 = array1[mid1];
            if(mid2 < m) r2 = array2[mid2];
            
            if(mid1 -1 >= 0) l1 = array1[mid1-1];
            if(mid2 -1 >= 0) l2 = array2[mid2-1];
            
            if(l1 > r2) high = mid1 - 1;
            else if(l2 > r1) low = mid1+1;
            else if(l1 <= r2 && l2 <= r1) {
                if((n+m)%2 == 0) return (double)(max(l1,l2) + min(r1,r2))/2.0;
                
                return max(l1,l2);
                
            }
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    
cout << "~" << "\n";
}
    return 0; 
}



// } Driver Code Ends