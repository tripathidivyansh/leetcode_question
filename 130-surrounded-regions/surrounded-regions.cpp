class Solution {
public:
    void Solve(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O'){
            
            return;
        }
        board[i][j] = '#';

        Solve(i + 1, j, board);
        Solve(i - 1, j, board);
        Solve(i, j + 1, board);
        Solve(i, j - 1, board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {

            if (board[i][0] == 'O') Solve(i, 0, board);
            if (board[i][m - 1] == 'O') Solve(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') Solve(0, j, board);
            if (board[n - 1][j] == 'O') Solve(n - 1, j, board);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';

                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
















