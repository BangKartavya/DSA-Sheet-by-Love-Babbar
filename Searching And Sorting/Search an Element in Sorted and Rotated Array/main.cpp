//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>, int);

// User code will be pasted here

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> vec(n);

        for(int i = 0; i < n; i++)
            cin >> vec[i];

        int target;
        cin >> target;

        cout << Search(vec, target) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends

// User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find

int pivot(vector<int>& vec, int s, int e) {
    if(vec[s] <= vec[e]) return s;

    int mid = s + (e - s) / 2;

    if(vec[mid] > vec[e]) return pivot(vec, mid + 1, e);

    else return pivot(vec, s, mid);
}

int search(vector<int>& vec, int s, int e, int& K) {
    if(s > e) return -1;

    int mid = s + (e - s) / 2;

    if(vec[mid] == K) return mid;

    else if(vec[mid] < K) return search(vec, mid + 1, e, K);

    else return search(vec, s, mid - 1, K);
}

int Search(vector<int> vec, int K) {
    int n = vec.size();

    int piv = pivot(vec, 0, n - 1);

    if(piv == 0) return search(vec, 0, n - 1, K);

    else {
        int s1 = search(vec, 0, piv, K);
        int s2 = search(vec, piv + 1, n - 1, K);

        return (s1 == -1) ? s2 : s1;
    }
}