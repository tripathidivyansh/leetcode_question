class Solution {
public:
    int solve(vector<int>&nums, int n, int target, vector<int>&dp){
        if(target < 0){
            return -1;
        }
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        dp[target]  = 0;
        for(int i = 0; i<nums.size(); i++){
            int res = solve(nums, n, target-nums[i], dp);

            if(res != -1){
                dp[target] += res;
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1, -1);
        return solve(nums, n, target, dp);
    }
};