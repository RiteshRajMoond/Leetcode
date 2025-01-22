class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> res(m,
                                vector<int>(n, INT_MAX)); // INT_MAX -> not vis

        queue<tuple<int, int, int>> q; // x,y,ht
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                    res[i][j] = 0;
                }
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty()) {
            auto [x, y, ht] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < m && nx >= 0 && ny < n && ny >= 0 && res[nx][ny] == INT_MAX) {
                    res[nx][ny] = ht+1;
                    q.push({nx, ny, ht+1});
                }
            }
        }

        return res;
    }
};