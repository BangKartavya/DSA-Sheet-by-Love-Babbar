//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
    private:
        void heapify(vector<int>& arr, int i, int n) {
            int largest = i;

            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if(l < n && arr[l] > arr[largest]) {
                largest = l;
            }
            if(r < n && arr[r] > arr[largest]) {
                largest = r;
            }

            if(largest != i) {
                swap(arr[largest], arr[i]);
                heapify(arr, largest, n);
            }
        }

    public:
        // Function to sort an array using Heap Sort.
        void heapSort(vector<int>& arr) {
            int n = arr.size();

            for(int i = n / 2 - 1; i >= 0; i--) {
                heapify(arr, i, n);
            }

            for(int i = n - 1; i > 0; i--) {
                swap(arr[0], arr[i]);
                heapify(arr, 0, i);
            }

            return;
        }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while(t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.heapSort(arr);
        for(int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends