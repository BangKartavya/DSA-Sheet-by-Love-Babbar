struct cmp {
   bool operator()( const vector<int> a, const vector<int> b ) const 
   {
    return a[0] < b[0];
   }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dists(n,INT_MAX);
        for(auto i: flights) {
            adj[i[0]].push_back({i[1],i[2]});
        }

        int ans = INT_MAX;

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push({0,src,0}); // {weight,node,total_stops,money_spent}

        while(!pq.empty()) {
            vector<int> top = pq.top();
            pq.pop();

            int weight = top[0];
            int node = top[1];
            int no_of_stops = top[2];

            cout << "weight : " << weight << endl;
            cout << "node : " << node << endl;
            cout << "no_of_steps : " << no_of_stops << endl;

            for(auto i: adj[node]) {
                int newNode = i.first;
                int newDist = weight + i.second;
                
                if(newDist < dists[newNode] && no_of_stops < k+1) {
                    dists[newNode] = newDist;
                    pq.push({newDist,newNode,no_of_stops+1});
                }
            }   

        }

        return dists[dest] == INT_MAX ? -1 : dists[dest];
    }
};