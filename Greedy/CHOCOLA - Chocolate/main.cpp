#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int solve(vector<int>& x, vector<int>& y) {
    int ans = 0;
    int i = 0;
    int j = 0;

    int n = x.size();
    int m = y.size();

    int hz = 1;
    int vr = 1;

    while(i < n && j < m) {
        if(x[i] > y[j]) {
            ans += x[i] * hz;
            vr++;
            i++;
        } else {
            ans += y[j] * vr;
            hz++;
            j++;
        }
    }

    while(i < n) {
        ans += x[i] * hz;
        vr++;
        i++;
    }
    while(j < m) {
        ans += y[j] * vr;
        hz++;
        j++;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m, n;
        cin >> m >> n;

        m--;
        n--;

        vector<int> x(m);
        vector<int> y(n);

        for(int i = 0; i < m; i++)
            cin >> x[i];
        for(int i = 0; i < n; i++)
            cin >> y[i];

        sort(begin(x), end(x), greater<int>());
        sort(begin(y), end(y), greater<int>());
        cout << solve(x, y) << endl;
    }

    return 0;
}