//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int freq[n+1];
        memset(freq,0,sizeof(freq));
        
        vector<int> v;
        
        for(auto i: arr) {
            if(freq[i] !=0) {
                v.push_back(i);
            }
            freq[i]++;
        }
        
        for(int i = 1;i<sizeof(freq);i++) {
            if(freq[i] == 0) {
                v.push_back(i);
                break;
            }
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends