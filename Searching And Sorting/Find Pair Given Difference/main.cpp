//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
    public:
        template <class T>
        static void input(vector<T>& A, int n) {
            for(int i = 0; i < n; i++) {
                scanf("%d ", &A[i]);
            }
        }

        template <class T>
        static void print(vector<T>& A) {
            for(int i = 0; i < A.size(); i++) {
                cout << A[i] << " ";
            }
            cout << endl;
        }
};

// } Driver Code Ends

class Solution {
    public:
        bool findPair(vector<int>& arr, int x) {
            sort(begin(arr), end(arr));

            int n = arr.size();

            for(int i = 0; i < n; i++) {
                int s = i;
                int e = n - 1;

                while(s <= e) {
                    int mid = s + (e - s) / 2;

                    if((arr[mid] == (x + arr[i])) && (mid != i)) return true;

                    else if(arr[mid] > (x + arr[i])) e = mid - 1;

                    else s = mid + 1;
                }
            }

            return false;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);

    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        int k;
        scanf("%d ", &k);
        Solution obj;

        cout << (obj.findPair(arr, k) ? "true" : "false") << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends