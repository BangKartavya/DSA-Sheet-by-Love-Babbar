//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
        int n;
        vector<int> arr;
        int k;
        
        bool helper(int maxPage) {
            int cnt = 1;
            int read = 0;
            
            for(int i = 0;i<n;i++) {
                if(arr[i] > maxPage) return false;
                
                if(read + arr[i] > maxPage) {
                    cnt++;
                    read = arr[i];
                    
                    if(cnt > k) return false;
                }
                
                
                else read+=arr[i];
            }
            
            return true;
        }
    public:
        int findPages(vector<int> &arr, int k) {
            n = arr.size();
            this->arr = arr;
            this->k = k;
            
            sort(begin(arr),end(arr));
            
            int sum = accumulate(begin(arr),end(arr),0);
            
            if(n < k) return -1;
            if(n == 1) return sum;
            
            int s = 0;
            int e = sum;
            int ans = -1;
            
            while(s <= e) {
                int mid = s + (e-s)/2;
                int maxi = helper(mid);
                if(maxi) {
                    ans = mid;
                    e = mid-1;
                }
                else {
                    s = mid+1;
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends