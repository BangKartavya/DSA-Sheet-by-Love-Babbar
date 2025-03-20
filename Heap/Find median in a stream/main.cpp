//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
        vector<double> getMedian(vector<int>& arr) {
            priority_queue<int> smallHeap;                            // maxHeap
            priority_queue<int, vector<int>, greater<int>> largeHeap; // minHeap
            int n = arr.size();
            vector<double> result(n);

            for(int i = 0; i < n; i++) {
                // default add it to smallHeap
                smallHeap.push(arr[i]);

                // check if max in small heap is greater than min in largeHeap

                if(!smallHeap.empty() && !largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
                    largeHeap.push(smallHeap.top());
                    smallHeap.pop();
                }

                if(smallHeap.size() > largeHeap.size() + 1) {
                    largeHeap.push(smallHeap.top());
                    smallHeap.pop();
                }

                if(largeHeap.size() > smallHeap.size() + 1) {
                    smallHeap.push(largeHeap.top());
                    largeHeap.pop();
                }

                if(i % 2 != 0) {
                    result[i] = ((double)smallHeap.top() + (double)largeHeap.top()) / (double)2;
                } else {
                    result[i] = smallHeap.size() > largeHeap.size() ? smallHeap.top() : largeHeap.top();
                }
            }

            return result;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while(ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for(auto& i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends