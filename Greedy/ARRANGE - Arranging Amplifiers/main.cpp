#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> amps;

        int ones = 0;

        for(size_t i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x == 1) {
                ones++;
                continue;
            }
            amps.push_back(x);
        }

        sort(begin(amps), end(amps));

        for(size_t i = 0; i < ones; i++) {
            cout << 1 << " ";
        }
        if(amps.size() == 2 && amps[0] == 2 && amps[1] == 3) {
            cout << 2 << " " << 3;
        } else {
            for(int i = amps.size() - 1; i >= 0; i--) {
                cout << amps[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
