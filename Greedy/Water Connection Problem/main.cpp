//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    vector<vector<pair<int,int>>> adj;

    pair<int,int> dfs(int node,int dia) {
        for(auto it: adj[node]) {
            dia = min(dia,it.second);
            return dfs(it.first,dia);
        }
        
        return {node,dia};
    }
        
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        adj.resize(n+1);
        vector<int> in(n+1);
        vector<int> out(n+1);
        
        for(int i = 0;i<p;i++) {
            adj[a[i]].push_back({b[i],d[i]});
            in[b[i]]++;
            out[a[i]]++;
        }
        
        vector<vector<int>> ans;
        
        for(int i = 1;i<=n;i++) {
            if(in[i] == 0 && out[i] > 0) {
                int dia = dfs(i,INT_MAX).second;
                int end = dfs(i,INT_MAX).first;
                ans.push_back({i,end,dia});
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends