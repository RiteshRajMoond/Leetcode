class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool> (n, false));

        auto bfs = [&] (int i, int j) -> int {
            int fish_count = 0;
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            queue<pair<int, int>> q;
            q.push({i, j});

            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if(vis[x][y]) continue;
                vis[x][y] = true;

                fish_count += grid[x][y];

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && ny >= 0 && ny < n && nx < m && grid[nx][ny] != 0 && !vis[nx][ny]) {
                        // ds.dsu(x * n + y, nx * n + ny);
                        q.push({nx, ny});
                    }
                }
            }
            return fish_count;
        };
        
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j]) res = max(res, bfs(i, j));
            }
        }
        return res;
    }
};