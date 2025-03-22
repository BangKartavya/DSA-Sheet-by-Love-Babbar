//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution {
    private:
        string addStrings(const string& a, const string& b) {
            int n = a.size();
            int m = b.size();

            int i = n - 1;
            int j = m - 1;

            int carry = 0;

            string result;

            while(i >= 0 && j >= 0) {
                int sum = (a[i] - '0') + (b[j] - '0') + carry;

                if(sum >= 10) {
                    carry = sum / 10;
                    sum %= 10;
                } else {
                    carry = 0;
                }
                result += to_string(sum);
                i--;
                j--;
            }

            if(carry) {
                result += to_string(carry);
            }

            while(result.size() >= 0 && result[result.size() - 1] == '0')
                result.pop_back();

            reverse(begin(result), end(result));

            return result;
        }

    public:
        string minSum(vector<int>& arr) {
            priority_queue<int, vector<int>, greater<int>> minHeap;

            for(int& i : arr)
                minHeap.push(i);

            string a;
            string b;

            while(minHeap.size() >= 2) {
                int first = minHeap.top();
                minHeap.pop();
                int second = minHeap.top();
                minHeap.pop();

                a += to_string(first);
                b += to_string(second);
            }

            if(!minHeap.empty()) {
                a += to_string(minHeap.top());
                minHeap.pop();
            }

            if(a.size() > b.size()) {
                b = "0" + b;
            } else if(b.size() > a.size()) {
                a = "0" + a;
            }

            return addStrings(a, b);
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while(ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends