//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
    public:
        // Function to find the maximum number of meetings that can
        // be performed in a meeting room.
        int maxMeetings(vector<int>& start, vector<int>& end) {
            vector<vector<int>> intervals;
            int n = start.size();

            for(int i = 0; i < n; i++) {
                intervals.push_back({start[i], end[i]});
            }

            sort(intervals.begin(), intervals.end(), cmp);

            int cnt = 0;
            int last = intervals[0][1];

            for(int i = 1; i < n; i++) {
                if(intervals[i][0] <= last) {
                    cnt++;
                } else last = intervals[i][1];
            }

            return n - cnt;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while(s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while(s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends