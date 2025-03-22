class Solution {
public:
    int solve(string& text1, string& text2, int i, int j, vector<vector<int>>&dp){
        if(i == text1.size()){
            return 0;
        }
        if(j == text2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solve(text1, text2, i+1, j+1, dp);
        }else{
            ans = max(solve(text1, text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
        }
        // return ans;
        dp[i][j] = ans;
        return ans;
    }
    string solve1(string& text1, string text2, vector<vector<int>>&dp){
        int i = 0, j = 0;
        string scs = "";
        while(i<text1.size() && j<text2.size()){
            if(text1[i] == text2[j]){
                scs += text1[i];
                i++;
                j++;
            }else if(dp[i+1][j] > dp[i][j+1]){
                scs += text1[i];
                i++;
            }else{
                scs += text2[j];
                j++;
            }
        }
        while(i < text1.size()){
            scs += text1[i];
            i++;
        }
        while(j < text2.size()){
            scs+= text2[j];
            j++;
        }
        return scs;
    }
    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1, vector<int>(text2.size()+1, -1));
        solve(text1, text2, 0, 0, dp);

        return solve1(text1, text2, dp);
    }
};