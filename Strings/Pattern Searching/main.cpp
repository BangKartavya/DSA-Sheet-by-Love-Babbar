//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
str: string in which pattern we have to find pattern.
pat: pattern needs to searched.
*/

bool searchPattern(string str, string pat) {
    int n = str.size();
    int m = pat.size();

    int badChar[255];
    memset(badChar, -1, sizeof(badChar));

    for(int i = 0; i < m; i++) {
        badChar[(int)pat[i]] = i;
    }

    int s = 0;
    while(s <= n - m) {
        int j = m - 1;

        while(j >= 0 && str[s + j] == pat[j])
            j--;

        if(j < 0) return true;

        else {
            if(badChar[(int)str[s + j]] == -1) s += j + 1;
            else s += max(1, m - badChar[(int)str[s + j]] - 1);
        }
    }

    return false;
}

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while(t--) {
        string str, pat;
        cin >> str;
        cin >> pat;

        if(searchPattern(str, pat) == true)
            cout << "Present" << endl;
        else
            cout << "Not present" << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends