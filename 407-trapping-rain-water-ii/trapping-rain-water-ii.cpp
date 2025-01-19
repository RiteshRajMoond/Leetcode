class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        int m = grid.size();
        int n = grid[0].size();

        // push border in pq;
        for(int i = 0; i < n; i++) {
            pq.push({grid[0][i], 0, i});
            pq.push({grid[m-1][i], m-1, i});
        }

        for(int i = 0; i < m; i++) {
            pq.push({grid[i][0], i, 0});
            pq.push({grid[i][n-1], i, n-1});
        }

        vector<vector<bool>> vis(m, vector<bool> (n, false));

        int res = 0;
        int max_h = -1;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!pq.empty()) {
            auto [ht, x, y] = pq.top(); pq.pop();

            if(vis[x][y]) continue;
            vis[x][y] = true;

            max_h = max(max_h, ht);
            res += (max_h - grid[x][y]);

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n && !vis[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return res;
    }
};


// 3 4 1 5 7
// 3 4 1 5 7
// 3 4 1 5 7
// 3 4 1 5 7

// bfs
// min-heap
// tuple -> ht, x, y