//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        vector<string> ans;
        int n;
        string s;
        void gen_sub(string str,int i) {
            if(i >= n) {
                if(str != "") ans.push_back(str);
                return;
            }
            
            gen_sub(str +s[i],i+1);
            gen_sub(str,i+1);
        }
        
	public:
		vector<string> AllPossibleStrings(string s){
		    n = s.size();
		    this->s = s;
		    
		    gen_sub("",0);
		    
		    sort(begin(ans),end(ans));
		    return ans;
		    
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends