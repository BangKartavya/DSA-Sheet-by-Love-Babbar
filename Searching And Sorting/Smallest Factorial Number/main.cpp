//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    private:
        int fives(int n) {
            if(n%5 != 0) return 0;
            
            int cnt = 0;
            while(n%5 == 0) {
                cnt++;
                n/=5;
            }
            return cnt;
        }
        
        int no_of_fives(int n) {
            if(n < 5) return 0;
            
            return fives(n) + no_of_fives(n-5);
        }
        
    public:
        int findNum(int n)
        {
            int s = 0;
            int e = n*5;
            int ans = -1;
            
            while(s <= e) {
                int mid = s + (e-s)/2;
                
                if(no_of_fives(mid - mid%5) >= n) {
                    ans = mid - mid%5;
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    
cout << "~" << "\n";
}
return 0;
}
// } Driver Code Ends