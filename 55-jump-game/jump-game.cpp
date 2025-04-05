class Solution {
public:

    bool solve(int index, vector<int>&nums, vector<int>&dp){
        if(index >= nums.size()-1){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int maxJump = nums[index];
        for(int i = 1; i<=maxJump; i++){
            if(solve(index + i, nums, dp)){
                dp[index] = true;
                return dp[index];
            }
        }
        dp[index] = false;
        return dp[index];
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};