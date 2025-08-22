class Solution {
public:
    int Solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size(), m = matrix[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(matrix[i][j] == 0) return dp[i][j] = 0;
        int up   = Solve(i-1, j, matrix, dp);
        int left = Solve(i, j-1, matrix, dp);
        int diag = Solve(i-1, j-1, matrix, dp);
        return dp[i][j] = 1 + min({up, left, diag});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int Sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                Sum += Solve(i, j, matrix, dp);
            }
        }
        return Sum;
    }

};



























