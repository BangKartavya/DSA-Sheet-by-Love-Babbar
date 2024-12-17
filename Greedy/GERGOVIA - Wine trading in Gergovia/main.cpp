#include <iostream>
#include <vector>
using namespace std;

long long int solve(vector<pair<int, int>>& buyer, vector<pair<int, int>>& seller) {
    int i = 0;
    int j = 0;

    int n = buyer.size();
    int m = seller.size();

    long long int total_work = 0;

    while(i < n && j < m) {
        int x = min(seller[j].first, buyer[i].first);
        int diff = abs(seller[j].second - buyer[i].second);

        buyer[i].first -= x;
        seller[j].first -= x;

        total_work += (x * diff);

        if(buyer[i].first == 0) {
            i++;
        }
        if(seller[j].first == 0) {
            j++;
        }
    }

    return total_work;
}

int main() {
    while(true) {
        int n;
        cin >> n;

        if(n == 0) break;

        vector<pair<int, int>> buyer;
        vector<pair<int, int>> seller;

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(x >= 0) {
                buyer.push_back({x, i});
            } else {
                seller.push_back({-x, i});
            }
        }

        // for(auto i : buyer)
        //     cout << i.first << " " << i.second << endl;
        // for(auto i : seller)
        //     cout << i.first << " " << i.second << endl;

        cout << solve(buyer, seller) << endl;
    }

    return 0;
}