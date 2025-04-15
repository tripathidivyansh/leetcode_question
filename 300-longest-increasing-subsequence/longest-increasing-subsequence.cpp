class Solution {
public:

    int solve(int index, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(index == nums.size()){
            return 0;
        }
        if(dp[index][prev+1] != -1){
            return dp[index][prev+1];
        }
        int take = 0;
        if(prev == -1 || nums[index] > nums[prev]){
            take = 1 + solve(index+1, index, nums, dp);
        }
        int nottake = solve(index+1, prev, nums, dp);
        dp[index][prev+1] = max(take, nottake);

        return dp[index][prev+1];
    }
    int lengthOfLIS(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solve(0, -1, nums, dp);
    }
};