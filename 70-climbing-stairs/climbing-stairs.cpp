class Solution {
public:
    int Solve(int index, int n, vector<int>&dp){
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(n == 2) return 2;
        if(dp[index] != -1) return dp[index];
        dp[index] = Solve(index + 1, n-1, dp) + Solve(index+2, n-2,dp);
        return dp[index];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return Solve(0, n, dp);
    }
};


