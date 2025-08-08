class Solution {
public:
    int dpJump(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (i >= n - 1) return 0; 

        if (dp[i] != -1) return dp[i];
        int ans = 1e9;
        for (int j = 1; j <= nums[i]; j++) {
            if (i + j < n) {
                ans = min(ans, 1 + dpJump(i + j, nums, dp));
            }
        }

        return dp[i] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return dpJump(0, nums, dp);
    }
};