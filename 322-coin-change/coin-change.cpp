class Solution {
public:
    int solve(int index, vector<int>&coins, int amount, vector<vector<int>>&dp){
        if(amount == 0){
            return 0;
        }
        if(index >= coins.size() || amount < 0){
            return 1e9;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int include = 1e9, exclude = 1e9;
        if(amount >= coins[index]){
            include = 1 + solve(index, coins, amount-coins[index], dp);
        }
        exclude = solve(index+1, coins, amount, dp);

        dp[index][amount] = min(include, exclude);
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int result = solve(0, coins, amount, dp);
        if(result >= 1e9){
            return -1;
        }
        return result;
    }
};