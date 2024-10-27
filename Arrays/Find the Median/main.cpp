//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(begin(v),end(v));
		    
		    int n = v.size();
		    
		    if(n % 2) {
		        return v[n/2];
		    }
		    else {
		        return (v[n/2] + v[n/2-1])/2;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends