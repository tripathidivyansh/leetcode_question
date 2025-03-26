class Solution {
public:

    bool solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i >= s.size() && j >= p.size()){
            return true;
        }
        if(j >= p.size()){
            return false;
        } 
        if(i >= s.size()){
            for(int k = j; k < p.size(); k++){
                if(p[k] != '*'){  
                    return false;
                }   
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        bool ans = false;
        if(p[j] == s[i] || p[j] == '?'){
            ans = solve(i+1, j+1, s, p, dp);
        }else if(p[j] == '*'){
            ans = solve(i, j+1, s, p, dp) || solve(i+1, j, s, p, dp);
        }
        return dp[i][j] = ans;
    } 
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, s, p, dp);
    }
};
