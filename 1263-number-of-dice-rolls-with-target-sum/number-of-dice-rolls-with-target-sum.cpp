class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>>&dp){
        if(target < 0){
            return 0;
        }
        if(n == 0){
            if(target == 0){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        long long  ans = 0;
        for(int i = 1; i<=k; i++){
            ans += solve(n-1, k, target-i, dp)% MOD;
        }
        dp[n][target] = ans% MOD;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};
