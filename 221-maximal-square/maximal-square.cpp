class Solution {
public:
    int solve(vector<vector<char>>&matrix, int i, int j, int &maxi, vector<vector<int>>&dp){
        if(i>=matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(matrix, i, j+1, maxi, dp);
        int left = solve(matrix, i+1, j, maxi, dp);
        int bottom = solve(matrix, i+1, j+1, maxi, dp);

        if(matrix[i][j] == '1'){
            dp[i][j] = 1 + min({right, left, bottom});
            maxi = max(maxi, dp[i][j]);
        }else{
            dp[i][j] = 0;
            return 0;
        }
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxi = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        solve(matrix, 0, 0, maxi, dp);
        return maxi*maxi;
    }
};