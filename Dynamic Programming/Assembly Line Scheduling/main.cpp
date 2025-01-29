//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++



class Solution {
  private:
  
  vector<vector<int>> a;
  vector<vector<int>> T;
  vector<int> e;
  vector<int> x;
  
  int n;
  
  vector<vector<int>> dp;
  
  int solve(bool line, int station) {
      if(station == n-1) {
          return a[line][station] + x[line];
      }
      
      if(dp[line][station] != -1) return dp[line][station];
      
      int straight = a[line][station] + solve(line,station+1);
      int changeLine = a[line][station] + T[line][station+1] + solve(!line,station+1);
      
      
      return dp[line][station] = min(straight,changeLine);
  }
  
  public:
  int carAssembly(vector<vector<int>>& a, 
  vector<vector<int>>& T, 
  vector<int>& e, 
  vector<int>& x) {
      this->a = a;
      this->T = T;
      this->e = e;
      this->x = x;
      
      n = a[0].size();
      
      dp.resize(2,vector<int>(n+1,-1));
      
      int line0 = e[0] + solve(false,0);
      int line1 = e[1] + solve(true,0);
      
      return min(line0,line1);
  }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(2,vector<int>(n)), T(2,vector<int>(n));
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>T[i][j];
            }
        }   
        vector<int> e(2), x(2);
        for(int i=0;i<2;i++){
            cin>>e[i];
        }
        for(int i=0;i<2;i++){
            cin>>x[i];
        }
        
        Solution ob;
        int ans = ob.carAssembly(a,T,e,x);
        
        cout<<ans<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends