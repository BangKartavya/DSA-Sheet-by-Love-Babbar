//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends

//User function Template for C++


class Solution
{
    private:
        vector<int> merge(const vector<int>& a, const vector<int>& b) {
            int i = 0;
            int n = a.size();
            
            int j = 0;
            int m = b.size();
        
            vector<int> result;
            
            while(i < n && j < m) {
                if(a[i] < b[j]) result.push_back(a[i++]);
                else result.push_back(b[j++]);
            }
            
            while(i < n) result.push_back(a[i++]);
            while(j < m) result.push_back(b[j++]);
            
            return result;
        }
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> result = arr[0];
        
        for(int i = 1;i<K;i++) {
            result = merge(result,arr[i]);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends