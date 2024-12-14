//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        int faults = 0;
        deque<int> mem;
        
        for(int i = 0;i<N;i++) {
            auto itr = find(begin(mem),end(mem),pages[i]);
            
            if(itr == mem.end()) {
                faults++;
                if(mem.size() < C) {
                    mem.push_back(pages[i]);
                }
                else {
                    mem.erase(mem.begin());
                    mem.push_back(pages[i]);
                }
            }
            else {
                mem.erase(itr);
                mem.push_back(pages[i]);
            }
        }
        return faults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends