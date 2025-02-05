class Solution {
    bool is_safe(vector<vector<char>>&board, int row, int col, char num) {
        // check in row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == num) return false;
        }

        // check in col
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == num) return false;
        }

        // check in the 3X3 box
        int s_row = (row/3)*3;
        int s_col = (col/3)*3;
        for(int i = s_row; i < s_row+3; i++) {
            for(int j = s_col; j < s_col+3; j++) {
                if(board[i][j] == num) return false;
            }
        }

        return true;
    }

    bool solve_sudoku(vector<vector<char>>& board, int row, int col) {
        if(row == 9) return true;

        int nxt_row = row, nxt_col = col+1;
        if(nxt_col == 9) {
            nxt_col = 0;
            nxt_row = row+1;
        }

        if(board[row][col] != '.') {
            return solve_sudoku(board, nxt_row, nxt_col);
        }

        for(int i = 1; i <= 9; i++) {
            char num = i + '0';
            if(!is_safe(board, row, col, num)) continue;
            board[row][col] = num;
            bool res = solve_sudoku(board, nxt_row, nxt_col);
            if(res) return true;
            board[row][col] = '.';
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve_sudoku(board, 0, 0);
    }
};