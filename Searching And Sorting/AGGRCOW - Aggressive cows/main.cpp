#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool canPlace(vector<int>& dist, int minD, int cows) {
    int cnt = 1;
    int last = dist[0];
    for(int i = 1; i < n; i++) {
        if(dist[i] - last >= minD) {
            cnt++;
            last = dist[i];
        }
        if(cnt >= cows) return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int c;

        cin >> n >> c;

        vector<int> dist(n, 0);

        for(int i = 0; i < n; i++) {
            cin >> dist[i];
        }

        sort(begin(dist), end(dist));

        int s = dist[0];
        int e = dist[n - 1];

        while(s <= e) {
            int mid = s + (e - s) / 2;
            if(canPlace(dist, mid, c)) {
                s = mid + 1;
            } else e = mid - 1;
        }

        cout << e << endl;
    }

    return 0;
}