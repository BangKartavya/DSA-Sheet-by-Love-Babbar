//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends

// you are required to complete this function
// function should print the required range
class Solution {
    public:
        pair<int, int> findSmallestRange(int KSortedArray[][N],
                                         int n, int k) {
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

            int left = KSortedArray[0][0];
            int right = KSortedArray[0][0];

            for(int i = 0; i < k; i++) {
                left = min(left, KSortedArray[i][0]);
                right = max(right, KSortedArray[i][0]);
                minHeap.push({KSortedArray[i][0], {i, 0}});
            }
            pair<int, int> result = {left, right};

            while(!minHeap.empty()) {
                pair<int, pair<int, int>> p = minHeap.top();
                minHeap.pop();

                int num = p.first;
                int listNumber = p.second.first;
                int idx = p.second.second;

                idx++;
                if(idx >= n) break;

                minHeap.push({KSortedArray[listNumber][idx], {listNumber, idx}});

                if(KSortedArray[listNumber][idx] > right) {
                    right = KSortedArray[listNumber][idx];
                }

                left = minHeap.top().first;

                if(result.second - result.first > right - left) {
                    result = {left, right};
                }
            }

            return result;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for(int i = 0; i < k; i++)
            for(int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends