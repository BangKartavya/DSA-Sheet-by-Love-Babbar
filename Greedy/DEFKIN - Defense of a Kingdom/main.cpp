#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solve(int* x, int* y, int n) {
    priority_queue<int, vector<int>, greater<int>> xPq(x, x + n + 1), yPq(y, y + n + 1);

    int curX, curY;

    int prevX = xPq.top();
    int prevY = yPq.top();

    xPq.pop();
    yPq.pop();

    int xMax = prevX;
    int yMax = prevY;

    while(!xPq.empty()) {
        curX = xPq.top();
        curY = yPq.top();

        xPq.pop();
        yPq.pop();

        xMax = max(xMax, curX - prevX);
        yMax = max(yMax, curY - prevY);

        prevX = curX;
        prevY = curY;
    }

    --xMax;
    --yMax;

    return xMax * yMax;
}

int main(int argc, char** argv) {
    int t;
    cin >> t;

    while(t--) {
        int w, h, n;

        cin >> w >> h >> n;

        int x[n + 1];
        int y[n + 1];

        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        x[n] = w + 1;
        y[n] = h + 1;

        cout << solve(x, y, n) << endl;
    }

    return 0;
}