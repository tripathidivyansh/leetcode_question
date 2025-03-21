class Solution {
public:

    int solve(int i, int j, string& s, vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i] == s[j]){
            ans = solve(i+1, j-1, s, dp);
        }else{
            ans = 1 + min(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, dp);
    }
};