class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> >pq;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool> (n, false));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        pq.push({grid[0][0], 0, 0}); // ele, r, c
        vis[0][0] = true;
        int res = grid[0][0];
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();

            int ht = get<0>(tp);
            int x = get<1>(tp);
            int y = get<2>(tp);

            res = max(res, ht);

            if(x == n-1 && y == n-1) return res;
            vis[x][y] = true;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return res;
    }
};