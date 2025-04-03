class Solution {
public:
    bool isSafe(int row, int coln, vector<vector<char>>& board, char digit) {
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][coln] == digit) {
                return false;
            }
        }
        int startrow = (row / 3) * 3;
        int startcoln = (coln / 3) * 3;
        for (int i = startrow; i < startrow + 3; i++) {
            for (int j = startcoln; j < startcoln + 3; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int row, int coln, vector<vector<char>>& board) {
        if (row == 9) {
            return true;
        }
        if (coln == 9) {
            return solve(row + 1, 0, board);
        }
        if (board[row][coln] != '.') {
            return solve(row, coln + 1, board);
        }
        for (char digit = '1'; digit <= '9'; digit++) {
            if (isSafe(row, coln, board, digit)) {
                board[row][coln] = digit;
                if (solve(row, coln + 1, board)) {
                    return true;
                }
                board[row][coln] = '.'; 
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0, 0, board);
    }
};
