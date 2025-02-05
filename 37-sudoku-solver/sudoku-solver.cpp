class Solution {
    bool is_safe(vector<vector<char>>& board, int row, int col, char num) {
        int s_row = (row/3)*3, s_col = (col/3)*3;
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == num || board[i][col] == num || board[s_row + i/3][s_col + i%3] == num)
                return false;
        }
        return true;
    }

    bool solve_sudoku(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;

        int nxt_row = row, nxt_col = col+1;
        if(nxt_col == 9) {
            nxt_row = row+1;
            nxt_col = 0;
        }

        if(board[row][col] != '.') return solve_sudoku(board, nxt_row, nxt_col);

        for(char num = '1'; num <= '9'; num++) {
            if(is_safe(board, row, col, num)) {
                board[row][col] = num;
                if(solve_sudoku(board, nxt_row, nxt_col)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve_sudoku(board, 0, 0);
    }
};