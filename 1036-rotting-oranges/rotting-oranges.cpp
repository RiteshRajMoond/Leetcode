class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int, int>> q; // r, c, time

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        int dx[] = {0, 1, 0, -1}; // u r d l
        int dy[] = {1, 0, -1, 0};

        int time = 0;
        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            int x = get<0>(ft);
            int y = get<1>(ft);
            int t = get<2>(ft);
            time = max(t, time);
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny, t+1});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return time;
    }
};