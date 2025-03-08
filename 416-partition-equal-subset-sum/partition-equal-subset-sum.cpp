class Solution {
public:
    bool solve(int index, vector<int>&nums, int n, int target, vector<vector<int>>&dp){
        if(index>= n){
            return 0;
        }
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return true;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        int include = solve(index+1, nums, n, target-nums[index], dp);
        int exclude = solve(index+1, nums, n, target, dp);

        dp[index][target] = include or exclude;
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i = 0; i<n; i++){
            totalsum += nums[i];
        }
        if(totalsum % 2 != 0){
            return 0;
        }
        int target = totalsum/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(0, nums, n, target, dp);
    }
};