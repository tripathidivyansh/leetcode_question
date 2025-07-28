class Solution {
public:
    int solve(int index, vector<int>&nums, vector<int>&dp){
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solve(index + 2, nums, dp); 
        int exclude = solve(index+1, nums, dp);

        dp[index] = max(include, exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solve(0, nums, dp);
    }
};