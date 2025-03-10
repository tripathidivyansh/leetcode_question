class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>&dp){
        if(i == word1.size()){
            return word2.size()-j;
        }
        if(j== word2.size()){
            return word1.size()-i;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(word1[i] == word2[j]){
            return solve(word1, word2, i+1, j+1, dp);
        }else{
            int insert = 1 + solve(word1, word2, i, j+1, dp);
            int delete1  = 1 + solve(word1, word2, i+1, j, dp);

            int replace = 1 + solve(word1, word2, i+1, j+1, dp);
            ans = min(insert, min(delete1, replace));
        }
        // return ans;
        dp[i][j] = ans;
        return dp[i][j];

    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};