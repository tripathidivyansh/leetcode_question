class Solution {
public:
    bool Solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>>&dp) {
        if (i == s1.size() && j == s2.size()) return true;
        int k = i + j;

        if(dp[i][j] != -1) return dp[i][j];
        if (i < s1.size() && s1[i] == s3[k]) {
            if (Solve(i + 1, j, s1, s2, s3, dp)) return dp[i][j] =  true;
        }
        if (j < s2.size() && s2[j] == s3[k]) {
            if (Solve(i, j + 1, s1, s2, s3, dp)) return dp[i][j] =  true;

        }
        dp[i][j] = false;
        // return false;
        
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return Solve(0, 0, s1, s2, s3, dp);
    }
};


