class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distance) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto&i : edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        auto dijkstra = [&](int src) -> int {   
            vector<int> dis(n, INT_MAX);
            priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
            pq.push({0, src});
            dis[src] = 0;

            while(!pq.empty()) {
                auto tp = pq.top();
                pq.pop();

                int d = tp.first;
                int node = tp.second;

                for(auto &i : adj[node]) {
                    int v = i.first;
                    int wt = i.second;

                    if(dis[v] > wt + d) {
                        dis[v] = wt + d;
                        pq.push({dis[v], v});
                    }
                }
            }

            int city = 0;
            for(int i = 0; i < n; i++) {
                if(i != src && dis[i] <= distance) city++;
            }
            return city;
        };

        int mn = INT_MAX, res = -1;

        for(int i = 0; i < n; i++) {
            int cur = dijkstra(i);
            if(cur < mn || (cur == mn && i > res)) {
                mn = cur;
                res = i;
            }
        }

        return res;
    }
};