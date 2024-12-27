class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<tuple<int, int, int>> q; // row, col, dis;
        q.push({0,0,1});
        vector<vector<bool>> vis(n, vector<bool> (n, false));

        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            int x = get<0>(ft);
            int y = get<1>(ft);
            int dis = get<2>(ft);

            if(x == n-1 && y == n-1) return dis;

            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    q.push({nx, ny, dis+1});
                }
            }
        }

        return -1;
    }
}; 