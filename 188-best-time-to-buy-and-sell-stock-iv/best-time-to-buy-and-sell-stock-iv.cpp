class Solution {
public:
    int solve(int index, int operation, int k,vector<int>&prices,  vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0;
        }
        if(operation == 2*k){
            return 0;
        }
        if(dp[index][operation] != -1){
            return dp[index][operation];
        }
        int profit = 0;
        if(operation % 2 == 0){
            int buy = -prices[index] + solve(index+1, operation+1, k, prices, dp);
            int notbuy  = 0+solve(index+1, operation, k, prices, dp);
            profit = max(buy, notbuy);
        }else{
            int sell = prices[index] + solve(index+1, operation+1, k, prices, dp);
            int notbuy = 0 + solve(index+1, operation, k, prices, dp);
            profit = max(sell, notbuy);
        }
        dp[index][operation] = profit;
        return dp[index][operation];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2*k, -1));
        return solve(0, 0, k, prices, dp);

    }
};