class Solution {
public:
    int solve(vector<int>&nums, int n, vector<int>&dp){
        if(n>= nums.size()){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int include = solve(nums, n+2, dp) + nums[n];
        int exclude = solve(nums, n+1, dp);

        dp[n] = max(include, exclude);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int ans = solve(nums, 0, dp);

        return ans;
    }
};