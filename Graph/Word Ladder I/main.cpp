//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        int n = startWord.size();
        unordered_set<string> vis;
        
        queue<pair<string,int>> q;
        q.push({startWord,1});
        vis.insert(startWord);
        
        if(startWord == targetWord) return 0;
        
        while(!q.empty()) {
            pair<string,int> top = q.front();
            q.pop();
            bool equal = true;
            for(int j = 0;j<n;j++) {
                if(top.first[j] != targetWord[j]) equal = false;
            }
            if(equal) return top.second;
            
            for(auto word: wordList) {
                if(vis.find(word) == vis.end()) {
                    
                    int delta = 0;
                    for(int j = 0;j<n;j++) {
                        if(top.first[j] != word[j]) delta++;
                    }
                    
                    if(delta > 1) continue;
                    
                    else if(delta == 0) {
                        return top.second;
                    }
                    else {
                        q.push({word,top.second+1});
                        vis.insert(word);
                    }
                }
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends