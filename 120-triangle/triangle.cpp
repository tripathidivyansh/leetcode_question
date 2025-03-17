class Solution {
public:

    int solve(int row, int col, vector<vector<int>>&triangle, vector<vector<int>>&dp){
        if(row == triangle.size()-1){
            return triangle[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = triangle[row][col] + solve(row+1, col, triangle, dp);
        int diagonal = triangle[row][col] + solve(row+1, col+1, triangle, dp);

        dp[row][col] = min(down, diagonal);
        return dp[row][col];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, 0, triangle, dp);
    }
};