//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
char* reverse(char* str, int len);
int main() {
    long long int t;
    cin >> t;
    while(t--) {
        char str[10000];
        cin >> str;
        long long int len = strlen(str);
        char* ch = reverse(str, len);
        for(int i = 0; i < len; i++) {
            cout << ch[i];
        }
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends

// return the address of the string
char* reverse(char* S, int len) {
    stack<char> stk;

    for(int i = 0; i < len; i++) {
        stk.push(S[i]);
    }

    char* result = new char[len];

    int i = 0;

    while(!stk.empty() && i < len) {
        result[i++] = stk.top();
        stk.pop();
    }

    return result;
}