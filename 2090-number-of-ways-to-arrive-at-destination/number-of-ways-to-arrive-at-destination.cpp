class Solution {
public:
    const int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> > pq; 
        vector<pair<long long, int>> dist(n, {LLONG_MAX, 0}); 

        pq.push({0, 0});
        dist[0] = {0, 1};

        while(!pq.empty()) {
            auto ft = pq.top();
            pq.pop();

            long long d = ft.first;
            int node = ft.second;

            if (d > dist[node].first) continue;

            for(auto&i : adj[node]) {
                int v = i.first;
                int wt = i.second;

                if(dist[v].first > d + wt) {
                    dist[v].first = d + wt;
                    dist[v].second = dist[node].second;
                    pq.push({dist[v].first, v});
                } else if (dist[v].first == d + wt) {
                    dist[v].second = (dist[v].second + dist[node].second) % mod;
                }
            }
        }
        return dist[n-1].second;
    }
};
