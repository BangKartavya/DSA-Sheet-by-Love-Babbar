//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 
    void search_start(vector<int>& arr,int s,int e, int x,int& start) {
        
        if(s > e) return;
        
        if(x < arr[0] || x > arr[e]) return;
        
        int mid = s + (e-s)/2;
        
        if(arr[mid] == x) {
            start = mid;
            search_start(arr,s,mid-1,x,start);
        }
        else if(arr[mid] < x) {
            search_start(arr,mid+1,e,x,start);
        }
        else search_start(arr,s,mid-1,x,start);
        
    }
    void search_end(vector<int>& arr,int s,int e, int x,int& end) {
        
        if(s > e) return;
        
        if(x < arr[0] || x > arr[e]) return;
        
        int mid = s + (e-s)/2;
        
        if(arr[mid] == x) {
            end = mid;
            search_end(arr,mid+1,e,x,end);
        }
        else if(arr[mid] < x) {
            search_end(arr,mid+1,e,x,end);
        }
        else search_end(arr,s,mid-1,x,end);
        
    }
    
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        
        int s = 0;
        int e = n-1;
        
        int start = -1;
        int end = -1;
        
        search_start(arr,s,e,x,start);
        search_end(arr,s,e,x,end);
        
        if(start==-1 || end == -1) return {-1,-1};
        
        return {start,end};
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, x);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends