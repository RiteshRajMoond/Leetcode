class Solution {
    vector<vector<int>> board;
    vector<vector<string>> res;

    void push_answer() {
        vector<string> temp;
        for (int i = 0; i < board.size(); i++) {
            string row(board.size(), '.'); 
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 1) {
                    row[j] = 'Q'; 
                }
            }
            temp.push_back(row);
        }
        res.push_back(temp);
    }

    bool is_safe(int r, int c) {
        // Check column
        for (int i = 0; i < r; i++) {
            if (board[i][c] == 1) return false;
        }

        // Check left diagonal
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) return false;
        }

        // Check right diagonal
        for (int i = r, j = c; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 1) return false;
        }

        return true;
    }

    void place_queens(int r, int n) {
        if (r == n) {
            push_answer();
            return;
        }

        for (int c = 0; c < n; c++) {
            if (is_safe(r, c)) {
                board[r][c] = 1;
                place_queens(r + 1, n);
                board[r][c] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, vector<int>(n, 0));
        place_queens(0, n);
        return res;
    }
};
