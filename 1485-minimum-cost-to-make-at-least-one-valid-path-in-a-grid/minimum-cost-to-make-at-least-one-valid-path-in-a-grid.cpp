class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int dx[] = {0, 1, 0, -1}; 
        int dy[] = {1, 0, -1, 0};

        pq.push({0, 0, 0}); // cost, x, y;

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1)
                return cost;

            if (vis[x][y])
                continue;

            vis[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < m && nx >= 0 && ny >= 0 && ny < n && !vis[nx][ny]) {
                    if ((grid[x][y] == 1 && i == 0) ||
                        (grid[x][y] == 2 && i == 2) ||
                        (grid[x][y] == 3 && i == 1) ||
                        (grid[x][y] == 4 && i == 3)) {
                        pq.push({cost, nx, ny});
                    } else {
                        pq.push({1 + cost, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};