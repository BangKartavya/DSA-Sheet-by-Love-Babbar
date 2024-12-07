//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    int setBits(int n) {
        int cnt = 0;
        
        while(n) {
            cnt += n%2;
            n/=2;
        }
        
        return cnt;
    }
    int pos(int n) {
        int cnt = 0;
        while(n%2 != 1) {
            cnt++;
            n/= 2;
        }
        
        return cnt+1;
    }
  public:
    int findPosition(int N) {
        int s = setBits(N);
        
        if(s != 1) return -1;
        
        return pos(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends