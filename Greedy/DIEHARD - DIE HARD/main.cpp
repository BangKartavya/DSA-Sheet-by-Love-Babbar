#include <iostream>
#include <cstring>
using namespace std;

int AIR = 0;
int WATER = 1;
int FIRE = 2;

int helper(int H, int A, int nextPos, int time) {
    if(H <= 0 || A <= 0) return time;

    if(nextPos == WATER) {
        H -= 5;
        A -= 10;
        if(H <= 0 || A <= 0) return time;

        return helper(H, A, AIR, time + 1);
    } else if(nextPos == AIR) {
        H += 3;
        A += 2;

        if(H > 5 && A > 10) {
            return helper(H, A, WATER, time + 1);
        }

        else if(H > 20) {
            return helper(H, A, FIRE, time + 1);
        } else return time + 1;
    } else {
        H -= 20;
        A += 5;

        if(H <= 0 || A <= 0) return time;

        return helper(H, A, AIR, time + 1);
    }
}

int solve(int H, int A) {
    H += 3;
    A += 2;

    if(H > 5 && A > 10) return helper(H, A, WATER, 1);

    else if(H > 20) return helper(H, A, FIRE, 1);

    return 1;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int H, A;

        cin >> H >> A;

        cout << solve(H, A) << endl;
    }
    return 0;
}