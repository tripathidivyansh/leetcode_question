class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_profit = INT_MAX;
        int max_profit = 0;
        for(int i = 0; i<n; i++){
            if(prices[i] < min_profit){
                min_profit = prices[i];
            }
            int profit = prices[i]-min_profit;
            if(profit > max_profit){
                max_profit = profit;
            }
        }
        return max_profit;
    }
};