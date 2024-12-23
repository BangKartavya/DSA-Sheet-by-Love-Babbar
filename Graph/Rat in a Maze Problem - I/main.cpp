//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    vector<vector<int>> mat;
    int n;
    vector<string> res;
    
    void solve(int x, int y,string ans) {
        if(x >= n || x < 0 || y >= n || y < 0) return;        
        
        if(x == n-1 && y == n-1) {
            res.push_back(ans);
            return;
        }
        // up -> x-1,y
        // down -> x+1,y
        // left -> x,y-1
        // right -> x,y+1
        mat[x][y] = 0;
        if(x-1 >= 0 && mat[x-1][y] != 0) solve(x-1,y,ans+"U");
        if(x+1 < n && mat[x+1][y] != 0) solve(x+1,y,ans+"D");
        if(y-1 >= 0 && mat[x][y-1] != 0) solve(x,y-1,ans+"L");
        if(y+1 < n && mat[x][y+1] != 0) solve(x,y+1,ans+"R");
        mat[x][y] = 1;
        return;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        this->mat = mat;
        n = mat.size();
        if(mat[n-1][n-1] == 0) return res;
        if(mat[0][0] == 0) return res;
        solve(0,0,"");
        sort(begin(res),end(res));
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends