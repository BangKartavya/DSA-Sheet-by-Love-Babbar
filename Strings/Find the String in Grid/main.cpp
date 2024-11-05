//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    
    bool found(vector<vector<char>>& grid,int i,int j,int idx,string& word,int dirX,int dirY) {
        if(i < 0 || j < 0 || i ==grid.size() || j == grid[0].size() || idx >= word.size() || grid[i][j] != word[idx]) {
            return false;
        }
        
        if(idx == word.size() - 1) {
            return true;
        }
        
        if(found(grid,i+dirX,j+dirY,idx+1,word,dirX,dirY)) return true;
        
        return false;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    set<vector<int>> s;
	    int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    for(int i =0 ;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            for(int k = 0;k<8;k++) {
                    if(found(grid,i,j,0,word,x[k],y[k]) ) {
                        s.insert({i,j});
                    }
	            }
	        }
	    }
	    vector<vector<int>> v;
	    for(auto i: s) v.push_back(i);
	    
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends