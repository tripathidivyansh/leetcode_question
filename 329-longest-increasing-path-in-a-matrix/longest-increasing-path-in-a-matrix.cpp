class Solution {
public:
    int Solve(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&dp){
        if(dp[i][j] != -1) return dp[i][j];
        int n = matrix.size();

        int m = matrix[0].size();
        int maxlen = 1;
        vector<int>dirX = {-1, 1, 0, 0};
        vector<int>dirY = {0, 0, -1, 1};
        for(int d = 0; d<4; d++){
            int newX = i + dirX[d];
            int newY = j + dirY[d];
            if(newX >= 0 && newX < n && newY >=0 && newY < m && matrix[newX][newY] < matrix[i][j]){
                maxlen = max(maxlen, 1 + Solve(newX, newY, matrix, dp));
            }
        }
        dp[i][j] = maxlen;

        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1, -1));
        int maxPath = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                maxPath = max(maxPath, Solve(i, j, matrix, dp));
            }
        }
        return maxPath;
    }
};