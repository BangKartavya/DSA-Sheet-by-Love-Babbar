//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largest_rectangle(int M[],int m) {
        stack<int> stk;
        int ans = 0;
        for(int i = 0;i<=m;i++) {
            while(!stk.empty() && (i == m || M[stk.top()] >= M[i])) {
                int height = M[stk.top()];
                stk.pop();
                
                int width;
                
                if(stk.empty()) width = i;
                else width = i-stk.top()-1;
                
                ans = max(ans,width*height);
            }
            stk.push(i);
        }
        return ans;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans = 0;    
        int height[m] = {0};
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(M[i][j] == 1) height[j]++;
                else height[j] = 0;
            }
            int area = largest_rectangle(height,m);
            
            ans = max(ans,area);
        }
    
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends