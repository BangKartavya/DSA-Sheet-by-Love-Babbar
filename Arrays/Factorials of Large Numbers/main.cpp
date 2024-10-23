//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.insert(ans.begin(),1);
        
        int size = 1;
        int c = 0;
        
        
        for(int i = 2;i<=N;i++) {
            int j = size;
            while(j - 1 >= 0) {
                int temp = ans[j-1]*i + c;
                ans[j-1] = temp%10;
                c = temp/10;
                j--;
            }
            
            while(c > 0) {
                ans.insert(ans.begin(),c%10);
                c/=10;
                size++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends