class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);

        for(auto& i : edges1) {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }

        for(auto& i : edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }

        auto bfs = [](int cur, vector<vector<int>>& adj) -> pair<int, int> {
            int n = adj.size();

            vector<bool> vis(n, false);
            queue<pair<int, int>> q; // node, dist
            q.push({cur, 0});

            pair<int, int> dia = {cur, 0}; // node, dist
            vis[cur] = true;
            while(!q.empty()) {
                auto ft = q.front();
                q.pop();
                
                for(int&i : adj[ft.first]) {
                    if(!vis[i]) {
                        vis[i] = true;
                        q.push({i, ft.second+1});
                        dia = {i, ft.second+1};
                    }
                }
            }
            return dia;
        };

        auto getDiameter = [&bfs](int cur, vector<vector<int>>& adj) -> int {
            auto sp = bfs(cur, adj);
            auto res = bfs(sp.first, adj);
            return res.second;
        };

        int d1 = getDiameter(0, adj1);
        int d2 = getDiameter(0, adj2);

        int cd = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1,d2,cd});
    }
};