class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dx[] = {0, 1, 0, -1}; // u r d l
        int dy[] = {1, 0, -1, 0};

        auto dfs = [&](auto& self, int x, int y) -> void {
            board[x][y] = 'A';

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = 'A';
                    self(self, nx, ny);
                }
            }
        };

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') dfs(dfs, i, 0);
            if(board[i][m-1] == 'O') dfs(dfs, i, m-1);
        }

        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O') dfs(dfs, 0, i);
            if(board[n-1][i] == 'O') dfs(dfs, n-1, i);
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};