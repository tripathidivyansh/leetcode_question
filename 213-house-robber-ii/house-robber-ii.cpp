class Solution {
public:

    int solve(int index, int end, vector<int>&nums, vector<int>&dp){
        if(index > end){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solve(index+2, end, nums, dp);
        int exclude = solve(index+1, end, nums, dp);

        dp[index] = max(include, exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int>dp1(n+1, -1);
        vector<int>dp2(n+1, -1);
        int case1 = solve(0, n-2, nums, dp1);
        int case2 = solve(1, n-1, nums, dp2);

        return max(case1, case2);
    }
};