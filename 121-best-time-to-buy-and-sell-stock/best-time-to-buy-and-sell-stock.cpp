class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], maxprofit = 0;

        for(int i = 0; i<n; i++){
            int profit = prices[i] - buy;
            maxprofit = max(maxprofit, profit);

            buy = min(buy, prices[i]);
        }
        
        return maxprofit;
    }
};


