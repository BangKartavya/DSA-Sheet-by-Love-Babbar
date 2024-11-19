//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
            int n = arr1.size();
            int m = arr2.size();

            bool check_first = n >= k;

            int i = n - 1;
            int j = 0;

            while(i >= 0 && j < m) {
                if(arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                    j++;
                }
                i--;
            }

            sort(begin(arr1), end(arr1));
            sort(begin(arr2), end(arr2));

            if(check_first) {
                return arr1[k - 1];
            }

            return arr2[k - n - 1];
        }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while(s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while(s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl
             << "~\n";
    }
    return 0;
}
// } Driver Code Ends