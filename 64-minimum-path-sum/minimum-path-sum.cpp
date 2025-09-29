class Solution {
public:
    int Solve(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m)return INT_MAX;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int right = Solve(i, j+1, grid, dp);
        
        int down = Solve(i+1, j, grid, dp);
        dp[i][j] = grid[i][j] + min(right, down);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return Solve(0, 0, grid, dp);

    }
};






























