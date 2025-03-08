class Solution {
public:
    int solve(int start, int buy, vector<int>&prices, int fee, vector<vector<int>>&dp){
        if(start>=prices.size()){
            return 0;
        }
        if(dp[start][buy] != -1){
            return dp[start][buy];
        }
        int profit = 0;
        if(buy){
            int buykaro = -prices[start] + solve( start+1, 0, prices, fee, dp);
            int skipkaro = 0 + solve(start+1, 1, prices, fee, dp);

            profit = max(buykaro, skipkaro);
        }else{
            int sellkaro = prices[start] - fee + solve(start+1, 1, prices, fee, dp);
            int skipkaro = 0+ solve(start+1, 0, prices, fee, dp);
            profit  = max(sellkaro, skipkaro);
        }
        dp[start][buy] = profit;
        return dp[start][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};