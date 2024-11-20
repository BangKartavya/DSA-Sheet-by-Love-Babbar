#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int n, m;

bool woodCut(vector<long long>& trees, long long int bladeHeight) {
    long long int wood = 0;
    for(int i = 0; i < n; i++) {
        if(trees[i] < bladeHeight) continue;

        wood += trees[i] - bladeHeight;
    }

    return wood >= m;
}

int main() {
    cin >> n >> m;

    vector<long long int> trees(n);

    for(int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    sort(begin(trees), end(trees));

    long long int s = 0;
    long long int e = trees[n - 1];
    long long int ans = -1;

    while(s <= e) {
        int mid = s + (e - s) / 2;

        if(woodCut(trees, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}