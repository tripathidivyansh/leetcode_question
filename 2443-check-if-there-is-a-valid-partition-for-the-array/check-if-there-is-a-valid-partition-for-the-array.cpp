class Solution {
public:
    bool Solve(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (i == n) return true;

        if (dp[i] != -1) return dp[i];
        if (i + 1 < n && nums[i] == nums[i+1]) {
            if (Solve(i + 2, nums, dp)) return dp[i] = 1;
        }
        if (i + 2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) {
            if (Solve(i + 3, nums, dp)) return dp[i] = 1;
        }
        if (i + 2 < n && nums[i+1] == nums[i] + 1 && nums[i+2] == nums[i+1] + 1) {
            if (Solve(i + 3, nums, dp)) return dp[i] = 1;
        }

        return dp[i] = 0; 
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);

        return Solve(0, nums, dp);
    }
};







