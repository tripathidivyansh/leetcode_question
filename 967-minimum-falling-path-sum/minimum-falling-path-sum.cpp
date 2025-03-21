class Solution {
public:
    int solve(int row, int colm, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if (colm < 0 || colm >= m) 
        return 1e9;
        
        if (row == n - 1) {
            return matrix[row][colm];
        }

        if (dp[row][colm] != INT_MAX) {
            return dp[row][colm];
        }

        int left = matrix[row][colm] + solve(row + 1, colm - 1, matrix, dp);
        int down = matrix[row][colm] + solve(row + 1, colm, matrix, dp);
        int right = matrix[row][colm] + solve(row + 1, colm + 1, matrix, dp);

        dp[row][colm] = min({left, down, right});
        return dp[row][colm];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));

        int minSum = 1e9;
        for (int col = 0; col < m; col++) {
            minSum = min(minSum, solve(0, col, matrix, dp));
        }
        return minSum;
    }
};
