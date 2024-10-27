//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
  public:
    bool isPal(int n) {
        int copyN = n;
        int revN = 0;
        int po = to_string(n).size()-1;
        while(n) {
            revN += pow(10, po) * (n % 10);
            po--;
            n /= 10;
        }
        
        return revN == copyN;
    }
    bool PalinArray(vector<int> &arr) {
        
        for(auto i: arr) {
            if(!isPal(i)) return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        cout << (ob.PalinArray(arr) ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends