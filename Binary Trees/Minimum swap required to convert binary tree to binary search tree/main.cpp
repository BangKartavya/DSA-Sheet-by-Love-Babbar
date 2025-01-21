//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        vector<int> inOrderArr;
        vector<int> arr;
        int n;

        void inOrder(int i) {
            if(i >= n) return;

            inOrder(2 * i + 1);
            inOrderArr.push_back(arr[i]);
            inOrder(2 * i + 2);
        }

    public:
        int minSwaps(vector<int>& arr) {
            this->arr = arr;
            n = arr.size();

            inOrder(0);

            vector<pair<int, int>> vp(n);

            for(int i = 0; i < n; i++) {
                vp[i] = {inOrderArr[i], i};
            }

            sort(begin(vp), end(vp));

            int swaps = 0;

            for(int i = 0; i < n; i++) {
                if(i == vp[i].second) continue;

                else {
                    swap(vp[i].first, vp[vp[i].second].first);
                    swap(vp[i].second, vp[vp[i].second].second);
                }

                if(i != vp[i].second) {
                    --i;
                }
                swaps++;
            }

            return swaps;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while(ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minSwaps(arr) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends