class Solution {
public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<int>>&dp) {
        if (index == prices.size()) {
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if (buy) {
            // profit = max(-prices[index] + solve(index + 1, 0, prices), 0 + solve(index + 1, 1, prices));  .
            int buyKaro = -prices[index] + solve(index+1, 0, prices, dp);
            int skipKaro = 0 + solve(index+1, 1, prices, dp);
            profit = max(buyKaro, skipKaro);
        } else {
            // profit = max(prices[index] + solve(index + 1, 1, prices),  0 + solve(index + 1, 0, prices));  
            int sellKaro =  prices[index] + solve(index+1, 1, prices, dp);
            int skipKaro = 0 + solve(index+1, 0, prices, dp);
            profit = max(sellKaro, skipKaro);
        }
        dp[index][buy] =  profit;
        // return profit;
        return dp[index][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
