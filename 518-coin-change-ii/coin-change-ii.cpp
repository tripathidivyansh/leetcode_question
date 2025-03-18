class Solution {
public:
    int solve(int index, int amount, vector<int>&coins, vector<vector<int>>&dp){
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size() || amount < 0){
            return 0;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int include = 0, exclude = 0;
        if(amount >0){
            include = solve(index, amount-coins[index], coins, dp);
        }
        exclude = solve(index+1, amount, coins, dp);

        dp[index][amount] = include + exclude;
        return dp[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solve(0, amount, coins, dp);
    }
};