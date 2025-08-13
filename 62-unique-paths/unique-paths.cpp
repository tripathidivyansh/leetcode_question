class Solution {
public: 
    int Solve(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i < 0 || j < 0 || i >= m || j >= n){
            return 0;
        }
        if(i == m-1 &&  j == n-1) return 1;
        if(dp[i][j] != -1)return dp[i][j];
        int right= Solve(i, j+1, m, n, dp);
        int bottom = Solve(i+1, j,m, n, dp);
        return dp[i][j] = right + bottom;;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, -1));
        return Solve(0, 0, m, n, dp);
    }
};
