class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto& i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> dis(n+1, INT_MAX);
        dis[0] = -1;
        dis[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, k}); // dis, node

        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            
            int d = tp.first;
            int node = tp.second;

            for(auto& i : adj[node]) {
                int v = i.first;
                int wt = i.second;

                if(dis[v] > d + wt) {
                    dis[v] = d + wt;
                    pq.push({dis[v], v});
                }
            }
        }

        int res = 0;
        for(int& i : dis) res = max(i, res);

        return res == INT_MAX ? -1 : res;
    }
};