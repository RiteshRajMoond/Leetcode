class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& i : flights) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;
        
        // priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        queue<tuple<int, int, int>> pq;
        pq.push({0, 0, src}); // dist, k, node

        while(!pq.empty()) {
            auto tp = pq.front();
            pq.pop();

            int d = get<0> (tp);
            int cnt = get<1> (tp);
            int node = get<2> (tp);

            if(cnt > k) break;

            for(auto& i : adj[node]) {
                int v = i.first;
                int wt = i.second;

                if(dis[v] > wt + d) {
                    dis[v] = wt + d;
                    if(cnt+1 <= k) pq.push({dis[v], cnt+1, v});
                }
            }
        }
        // return -1;
        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};