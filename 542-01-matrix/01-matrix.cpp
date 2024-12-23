class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        
        queue<tuple<int, int, int>> q; // r, c, dis
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = true;
                }
            }
        }

        int dx[] = {0, 1, 0, -1}; // u r d l
        int dy[] = {1, 0,-1, 0};

        while(!q.empty()) {
            auto ft = q.front(); q.pop();
            int x = get<0>(ft);
            int y = get<1>(ft);
            int dist = get<2>(ft);

            res[x][y] = dist;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    int ndis = (mat[nx][ny] == 0) ? 0 : dist+1;
                    q.push({nx, ny, ndis});
                    vis[nx][ny] = true;
                }
            }
        }

        return res;
    }
};