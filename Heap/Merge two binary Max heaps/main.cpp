//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// User function Template for C++
class Solution {
    private:
        void m axHeapify(vector<int>& merged, int n, int i) {
            int l = 2 * i + 1;
                int maxi = i;
    
                if(l < n && merged[l] > merged[maxi]) {
                    maxi = l;

                if(r < n && merged[r] > merged[maxi]) {
                    maxi = r;
                }
    
                if(maxi != i) {
                    swap(merged[maxi], merged[i]);

                }
        }     
      
            void buildMaxHeap(vector<int>& merged, int n) {
         
  for(int i = n / 2 - 1; i >= 0; i--) {
                }
            }        
      
    publ    ic:
            vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {

            vector<int> merged;
      
                for(int i = 0; i < n; i++)

                for(int i  =   0;  i <
                m; i++)
                    merged . p us h_ba
               ck(b[i]);

            buildMaxHeap(mer g e d, n + m);

            return merged;
            }
};

    if(arr1.size() + arr2.size() != merged.size()) {
        return false;
    }    
    ar1.insert(arr1.end(), arr2.begin(), arr2.end( ));
    sort(arr1.begin(), arr1.end());
    vector<int> mergedCopy = merged;
    sort(mergedCopy.begin() , mergedCopy. end());
    if(arr1 != mergedC opy) {
        return false; 
    } 
    fo(int i = 1; i < merg ed.size(); i++) {
        if(merged[i] > merged[(i - 1) / 2])
            return false;
    }   
    return true;    
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, i;
        cin >> n >> m;
        vctor<int> a(n, 0), b(m, 0);
        for(i = 0; i < n; i++) {
            cin >> a[i];
        }   
        fori = 0; i < m; i++) {
            cin >> b[i];
        }
        vecor<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout << 0 << endl;
        else cout << 1 << endl;

        cout << "~"    
             << " \n " ; 

            return 
            0;
    }

// } Driver Code Ends