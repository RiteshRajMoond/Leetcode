class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto& i : flights) adj[i[0]].push_back({i[1], i[2]});

        queue<tuple<int, int, int>> q;
        vector<int> dis(n, 1e9);
        q.push({0, 0, src}); // stops, dis, node

        dis[src] = 0;

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            int st = get<0>(ft);
            int d = get<1>(ft);
            int node = get<2>(ft);

            if(st > k) break;

            for(auto& i : adj[node]) {
                int v = i.first;
                int wt = i.second;

                if(dis[v] > wt + d) {
                    dis[v] = wt + d;
                    q.push({st+1, dis[v], v});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};