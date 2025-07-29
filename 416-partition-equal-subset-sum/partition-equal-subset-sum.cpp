class Solution {
public:
    bool solve(int index, vector<int>&nums, int target, vector<vector<int>>&dp){
        int n = nums.size();
        if(index >= n) return 0;
        if(target < 0) return 0;
        if(target == 0) return true;
        if(dp[index][target] != -1) return dp[index][target];
        int take = solve(index+1, nums, target-nums[index], dp);
        int nottake = solve(index+1, nums, target, dp);
        dp[index][target] = max(take, nottake);
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i<n; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(0, nums, target, dp);
    }
};