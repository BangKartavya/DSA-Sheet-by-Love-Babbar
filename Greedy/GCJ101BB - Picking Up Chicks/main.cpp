#include <iostream>
#include <vector>
using namespace std;

long long int solve(vector<int>& x, vector<int>& v, int b, int k, int t) {
    int n = x.size();

    long long int cnt = 0;
    long long int cannot_cnt = 0;

    long long int swaps = 0;

    for(int i = n - 1; i >= 0; i--) {
        long long int toCover = (b - x[i]);
        long long int canCover = v[i] * t;

        if(canCover >= toCover) {
            cnt++;

            if(cannot_cnt > 0) {
                swaps += cannot_cnt;
            }
        } else {
            cannot_cnt++;
        }
        if(cnt >= k) return swaps;
    }

    return -1;
}

int main() {
    int t;
    cin >> t;
    int cnt = 0;
    while(cnt < t) {
        int n, k, b, t;
        cin >> n >> k >> b >> t;

        vector<int> initial_pos(n);
        vector<int> natural_speed(n);

        for(int i = 0; i < n; i++) {
            cin >> initial_pos[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> natural_speed[i];
        }

        int S = solve(initial_pos, natural_speed, b, k, t);
        if(S != -1) cout << "Case #" << cnt + 1 << ": " << S << endl;
        else cout << "Case #" << cnt + 1 << ": IMPOSSIBLE" << endl;
        cnt++;
    }

    return 0;
}