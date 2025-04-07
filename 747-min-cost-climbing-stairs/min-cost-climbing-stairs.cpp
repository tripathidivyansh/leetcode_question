class Solution {
public:
    int solve(int index, vector<int>&cost, vector<int>&dp){
        if(index >= cost.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int oneStep = solve(index+1, cost, dp);
        int secondStep = solve(index+2, cost, dp);

        dp[index] = cost[index] + min(oneStep, secondStep);
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);

        return min(solve(0, cost, dp), solve(1, cost, dp));
        
    }
};