class Solution {
    vector<vector<bool>> vis;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool is_valid(int x, int y, int m, int n) {
        if(x >= 0 && x < m && y >= 0 && y < n) return true;
        return false;
    }

    bool is_word_present(int idx, int x, int y, vector<vector<char>>& grid, string& word) {
        if(idx == word.size()) return true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(is_valid(nx, ny, grid.size(), grid[0].size()) && !vis[nx][ny] && word[idx] == grid[nx][ny]) {
                vis[nx][ny] = true;
                bool res = is_word_present(idx+1, nx, ny, grid, word);
                vis[nx][ny] = false;
                if(res) return true;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        vis.assign(m, vector<bool> (n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = true;
                    bool res = is_word_present(1, i, j, board, word);
                    if(res) return true;
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }
};