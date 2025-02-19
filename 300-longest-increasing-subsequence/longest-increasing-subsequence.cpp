class Solution {
public:
    int solve(int n, vector<int>&nums, int curr, int prev, vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int take = 0;
        if(prev == -1 || nums[curr] >nums[prev]){
            take = 1+ solve(n, nums, curr+1, curr, dp);
        }
        int nottake = 0 + solve(n, nums, curr+1, prev, dp);

        dp[curr][prev+1] = max(take,nottake);
        return dp[curr][prev+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(n, nums, 0, -1, dp);
    }
};