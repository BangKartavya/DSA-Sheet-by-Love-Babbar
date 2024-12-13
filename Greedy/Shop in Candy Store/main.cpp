//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
        vector<int> candyStore(int candies[], int N, int K) {
            if(K == N - 1) {
                return {*min_element(candies, candies + N), *max_element(candies, candies + N)};
            }

            sort(candies, candies + N);
            int cnt = 0;
            int min_money = 0;
            int i = 0;

            while(cnt < N) {
                min_money += candies[i];
                i++;
                cnt += K + 1;
            }

            i = N - 1;
            cnt = 0;
            int max_money = 0;

            while(cnt < N) {
                max_money += candies[i];
                i--;
                cnt += K + 1;
            }

            return {min_money, max_money};
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for(int i = 0; i < N; i++) {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends