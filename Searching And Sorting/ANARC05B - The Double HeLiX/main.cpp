#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> v1(n);

        for(int i = 0; i < n; i++)
            cin >> v1[i];

        int m;
        cin >> m;

        vector<int> v2(m);

        for(int i = 0; i < m; i++)
            cin >> v2[i];

        int sum = 0;

        int i = 0;
        int j = 0;
        int sum_i = 0;
        int sum_j = 0;
        bool curr = v1[i] < v2[j];

        while(i < n && j < m) {
            if(v1[i] < v2[j]) {
                sum_i += v1[i];
                i++;

            } else if(v1[i] > v2[j]) {
                sum_j += v2[j];
                j++;
            } else {
                curr = sum_i < sum_j;
                if(curr) {
                    sum += sum_j;
                    sum += v2[j];
                } else {
                    sum += sum_i;
                    sum += v1[i];
                }
                i++;
                j++;
                sum_j = 0;
                sum_i = 0;
            }
        }

        while(i < n)
            sum_i += v1[i++];
        while(j < m)
            sum_j += v2[j++];

        sum += sum_i > sum_j ? sum_i : sum_j;

        cout << sum << endl;
    }

    return 0;
}