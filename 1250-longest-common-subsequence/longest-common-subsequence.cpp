class Solution {
public:

    int solve(int i, int j, string &text1, string &text2, vector<vector<int>>&dp){
        if(i == text1.size() || (j == text2.size())){
            return 0;
        }
        // if(j == text2.size()){
        //     return 0;
        // }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int take = 0;
        if(text1[i] == text2[j]){
            take = 1 + solve(i+1, j+1, text1, text2, dp);
        }
        int nottake = max(solve(i+1, j, text1, text2, dp), solve(i, j+1, text1, text2, dp));

        dp[i][j] = max(take, nottake);
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, text1, text2, dp);
    }
};