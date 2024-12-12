//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented

struct Item{
    int value;
    int weight;
    double val_wt;
};

bool cmp(Item& a, Item& b) {
    return a.val_wt >= b.val_wt;
}

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int total_wt = accumulate(begin(wt),end(wt),0);
        int n = val.size();
        
        if(total_wt <= capacity) {
            double total_val = 0;
            for(auto i: val) {
                total_val += i;
            }
            
            return total_val;
        }
        
        vector<Item> v;
        for(int i = 0;i<n;i++) {
            v.push_back({val[i],wt[i],(double)val[i]/(double)wt[i]});
        }
        
        sort(begin(v),end(v),cmp);
        double ans = 0;
        int i = 0;
        while(capacity) {
            if(capacity > v[i].weight) {
                capacity -= v[i].weight;
                ans += v[i].value;
                i++;
            }
            else {
                ans += v[i].val_wt * (double)capacity;
                capacity = 0;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends