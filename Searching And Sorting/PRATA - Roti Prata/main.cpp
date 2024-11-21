#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& freq, int& L, int mid, int& P) {
    int cnt = 0;

    for(int i = 0; i < L; i++) {
        int time = freq[i];
        int mul = 2;
        while(time <= mid) {
            cnt++;
            time += (freq[i] * mul);
            mul++;
        }
        if(cnt >= P) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int P;
        cin >> P;
        int L;
        cin >> L;

        vector<int> freq(L);

        for(int i = 0; i < L; i++) {
            cin >> freq[i];
        }

        sort(begin(freq), end(freq));

        int s = 0;
        int e = 1e9;
        int ans = -1;

        while(s <= e) {
            int mid = s + (e - s) / 2;

            if(possible(freq, L, mid, P)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}