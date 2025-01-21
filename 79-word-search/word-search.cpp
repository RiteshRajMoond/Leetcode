class Solution {
public:
    vector<vector<bool>> vis;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vis = vector<vector<bool>>(m, vector<bool> (n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    vis[i][j] = true;
                    bool res = f(board, word, i, j, 1);
                    if (res)
                        return true;
                    vis[i][j] = false;
                }
            }
        }

        return false;
    }

private:
    bool f(vector<vector<char>>& board, string& word, int x, int y, int idx) {
        if (idx == word.size())
            return true;
        vis[x][y] = true;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < board.size() &&
                ny < board[0].size() && !vis[nx][ny] && board[nx][ny] == word[idx]) {
                vis[nx][ny] = true;
                bool res = f(board, word, nx, ny, idx + 1);
                if (res)
                    return true;
                vis[nx][ny] = false;
            }
        }

        return false;
    }
};