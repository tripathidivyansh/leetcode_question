class Solution {
public:
    int solve(int&m, int&n, int &count, int i, int j, vector<vector<int>>&dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(i == m - 1 && j == n - 1){
            count++;
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(m, n, count, i, j + 1, dp);
        int down = solve(m, n, count, i + 1, j, dp); 

        return dp[i][j] = right + down; 
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1)); 
        int count = 0;

        return solve(m, n, count, 0, 0, dp); 
    }
};
