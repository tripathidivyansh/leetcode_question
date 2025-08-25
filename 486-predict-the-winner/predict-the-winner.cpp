class Solution {
public:
    int Solve(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i == j) return nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int leftpick = nums[i] - Solve(i+1, j, nums, dp);
        int rightpick = nums[j] - Solve(i, j-1, nums, dp);
        int maxi = max(leftpick, rightpick);
        dp[i][j] = maxi;
        return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int Score =  Solve(0, n-1, nums, dp);
        if(Score >= 0){
            return true;
        }else{
            return false;
        }
    }
};