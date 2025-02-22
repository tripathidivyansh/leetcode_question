class Solution {
public:
    int solve(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start > end) {
            return 0;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        int include = nums[start] + solve(nums, start + 2, end, dp);
        int exclude = solve(nums, start + 1, end, dp);

        dp[start] = max(include, exclude);
        return dp[start];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n+1, -1);
        vector<int> dp2(n+1, -1);

        int case1 = solve(nums, 0, n - 2, dp1);
        int case2 = solve(nums, 1, n - 1, dp2); 

        return max(case1, case2);
    }
};
