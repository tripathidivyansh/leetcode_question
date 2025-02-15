class Solution {
public:
    int solve(int n, int& count, vector<int>&dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int ans = n;
        for(int i = 1; i*i<=n; i++){
            int temp = i*i;
            ans = min(ans, 1 + solve(n - temp, count, dp));      
            if(ans != -1){
                dp[n] = ans;
                count++;
            }    
        }

        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        int count = 0;
        return solve(n, count, dp);
    }
};