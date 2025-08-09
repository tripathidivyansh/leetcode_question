class Solution {
public:
    int solve(int row, int colm, vector<vector<int>>& matrix, vector<vector<int>>& dp ,int n) {

        if (colm < 0 || colm >= n ) return 1e9;
        
        if (row == n - 1) {
            return matrix[row][colm];
        }

        if (dp[row][colm] != INT_MAX) {
            return dp[row][colm];
        }

        int left = matrix[row][colm] + solve(row + 1, colm - 1, matrix, dp , n);
        int down = matrix[row][colm] + solve(row + 1, colm, matrix, dp , n);
        int right = matrix[row][colm] + solve(row + 1, colm + 1, matrix, dp , n);

        return dp[row][colm] = min(left,min(right,down));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));

        int minSum = 1e9;
        for (int col = 0; col < n; col++) {
            minSum = min(minSum, solve(0, col, matrix, dp , n));
        }
        return minSum;
    }
};
