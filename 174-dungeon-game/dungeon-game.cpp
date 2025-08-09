class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&dungeon, vector<vector<int>>&dp){
        int n = dungeon.size();
        int m = dungeon[0].size();

        if(i >= n || j >= m) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1 && j == m-1){
            return max(1, 1-dungeon[i][j]);
        }
        int right = solve(i, j+1, dungeon, dp);
        int bottom = solve(i+1, j, dungeon, dp);
        int minnext = min(right, bottom);
        dp[i][j] = max(1, minnext-dungeon[i][j]);
        return dp[i][j];

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();

        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, dungeon, dp);
    }
};