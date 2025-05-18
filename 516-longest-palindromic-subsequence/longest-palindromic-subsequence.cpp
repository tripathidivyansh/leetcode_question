class Solution {
public:
    int solve(string& s, string& s1, int i, int j, vector<vector<int>>&dp){
        if(i>= s.size() || j>= s1.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int count = 0;
        if(s[i] == s1[j]){
            count = 1 + solve(s, s1, i+1, j+1, dp);
        }else{
            count = max(solve(s, s1, i+1, j, dp), solve(s, s1, i, j+1, dp));
        }
        dp[i][j] = count;
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(s, s1, 0, 0, dp);
    }
};