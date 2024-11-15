//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int max_elem = arr[0];
        int cnt = 1;
        
        for(int i = 1;i<n;i++) {
            if(arr[i] == max_elem) cnt++;
            else {
                if(cnt == 0) {
                    max_elem = arr[i];
                    cnt = 1;
                    continue;
                }
                cnt--;
            }
        }
        
        int last_cnt = 0;
        
        for(int i = 0;i<n;i++) if(arr[i] == max_elem) last_cnt++;
        
        return last_cnt > n/2 ? max_elem : -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends