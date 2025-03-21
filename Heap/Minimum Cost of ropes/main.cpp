//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int& i: arr) {
            pq.push(i);
        }
        
        int totalCost = 0;
        
        while(pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            pq.push(a + b);
            totalCost += (a+b);
            
        }
        
        return totalCost;
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
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends