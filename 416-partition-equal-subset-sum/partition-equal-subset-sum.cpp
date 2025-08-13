class Solution {
public:
    bool Solve(int index, vector<int>&nums, vector<vector<int>>&dp, int target){
        if(index >= nums.size()) return false;
        if(target < 0) return 0;

        if(target == 0) return true;
        if(dp[index][target] != -1) return dp[index][target];
        int take = Solve(index+1, nums, dp, target - nums[index]);
        
        int nottake = Solve(index+1, nums, dp, target);
        dp[index][target] = max(take, nottake);
        
        return dp[index][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i<nums.size(); i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        int target = totalSum /2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return Solve(0, nums, dp,target);
    }
};




