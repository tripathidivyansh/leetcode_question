class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if (index >= n - 1) {
            return 0;
        }
        if (nums[index] == 0) {
            return 1e9;  
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int minJumps = 1e9;
        for (int i = 1; i <= nums[index]; i++) {
            if (index + i < n) {  
                int jumpsFromNext = solve(index + i, nums, dp);
                if (jumpsFromNext < minJumps) {
                    minJumps = jumpsFromNext;
                }
            }
        }
        dp[index] = 1 + minJumps;
        return dp[index];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); 
        int result = solve(0, nums, dp);

        if (result >= 1e9) {
            return -1;
        } else {
            return result;
        }
    }
};
