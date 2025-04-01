class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index] || visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool found = solve(i + 1, j, board, word, index + 1, visited) || 
                     solve(i - 1, j, board, word, index + 1, visited) ||  
                     solve(i, j + 1, board, word, index + 1, visited) ||  
                     solve(i, j - 1, board, word, index + 1, visited);
        visited[i][j] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, board, word, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
