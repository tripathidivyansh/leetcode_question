class Solution {
public:

    int MOD = 1e9 + 7;
    int solve(int i, int j, int sum, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp, int k){
        if(i >= grid.size()){
            return 0;
        }
        if(j < 0 || j >= grid[0].size()){
            return 0;
        }
        sum += grid[i][j];

        if(i == grid.size()-1 && j == grid[0].size()-1){
            if(sum % k == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[i][j][sum % k] != -1){
            return dp[i][j][sum % k];
        }
        int down = solve(i+1,j,sum,grid, dp, k);
        int up = solve(i, j+1, sum, grid, dp, k);

        dp[i][j][sum%k] = (down + up)%MOD;
        return dp[i][j][sum%k];
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));
        return solve(0, 0, 0, grid, dp, k);
    }
};