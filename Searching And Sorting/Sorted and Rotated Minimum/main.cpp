//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pivot(vector<int>& arr,int s,int e) {
        if(arr[s] <= arr[e]) return s;
        
        int mid = s + (e-s)/2;
        
        if(arr[mid] >= arr[s]) {
            return pivot(arr,mid+1,e);
        }
        
        return pivot(arr,s,mid);
    }
    int findMin(vector<int>& arr) {
        
        return arr[pivot(arr,0,arr.size()-1)];
        
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
    }
    return 0;
}

// } Driver Code Ends