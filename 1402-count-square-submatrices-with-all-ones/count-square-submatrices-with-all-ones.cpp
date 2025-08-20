class Solution {
public:
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (matrix[i][j] == 0) return dp[i][j] = 0;

        int up = solve(matrix, i-1, j, dp);
        int left = solve(matrix, i, j-1, dp);
        int diag = solve(matrix, i-1, j-1, dp);

        return dp[i][j] = 1 + min({up, left, diag});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += solve(matrix, i, j, dp);
            }
        }
        return sum;
    }
};


