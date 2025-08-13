class Solution {
public:
    int Solve(int index, vector<int>&cost, vector<int>&dp){
        if(index >= cost.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int oneStep = Solve(index+1, cost, dp);
        int twoStep = Solve(index+2, cost, dp);
        dp[index] = cost[index] + min(oneStep, twoStep);
        
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);

        return min(Solve(0, cost, dp), Solve(1, cost, dp));
    }
};