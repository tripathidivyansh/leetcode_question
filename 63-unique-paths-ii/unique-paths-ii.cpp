class Solution {
public:

    int solve(int i, int j, int n, int m, vector<vector<int>>&obstacleGrid, vector<vector<int>>&dp){
        if(i>=n || j >= m || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == n - 1 && j == m - 1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = solve(i+1, j, n, m, obstacleGrid, dp);
        int bottom = solve(i, j+1, n, m, obstacleGrid, dp);
        dp[i][j] = right+bottom;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, n, m, obstacleGrid, dp);
    }
};