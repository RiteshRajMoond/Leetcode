class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        // create a min-heap
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        int m = grid.size();
        int n = grid[0].size();

        // push the borders in
        for(int i = 0; i < n; i++) {
            pq.push({grid[0][i], 0, i}); // ht, x, y
            pq.push({grid[m-1][i], m-1, i});
        }

        for(int i = 0; i < m; i++) {
            pq.push({grid[i][0], i, 0});
            pq.push({grid[i][n-1], i, n-1});
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        vector<vector<bool>> vis(m, vector<bool> (n, false));

        int res = 0;
        int max_h = -1;

        // bfs
        while(!pq.empty()) {
            auto [ht, x, y] = pq.top(); pq.pop();
            max_h = max(ht, max_h);

            if(vis[x][y]) continue;
            vis[x][y] = true;

            res += (max_h - ht);

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return res;
    }
};