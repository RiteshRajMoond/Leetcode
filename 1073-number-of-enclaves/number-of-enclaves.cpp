class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> temp = grid;

        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            if (temp[i][0] == 1) q.push({i, 0});
            if(temp[i][m-1] == 1) q.push({i, m-1});
        }

        for(int i = 0; i < m; i++) {
            if(temp[0][i] == 1) q.push({0, i});
            if(temp[n-1][i] == 1) q.push({n-1, i});
        }

        int dx[] = {0, 1, 0, -1}; // u r d l
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();
            int x = ft.first;
            int y = ft.second;

            temp[x][y] = 2;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && temp[nx][ny] == 1) {
                    q.push({nx, ny});
                    temp[nx][ny] = 2;
                }
            }
        }

        int res = 0;
        for(auto& i : temp) {
            for(int& j : i) {
                if(j == 1) res++;
            }
        }

        return res;
    }
};