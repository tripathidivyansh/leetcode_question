class Solution {
public:
    int solve1(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (index == arr.size()) {
            if (target == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        int take = 0;
        if (arr[index] <= target) {
            take = solve1(index + 1, target - arr[index], arr, dp);
        }
        int nottake = solve1(index + 1, target, arr, dp);

        dp[index][target] = take + nottake;
        return dp[index][target];
    }
    int solve(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve1(0, target, arr, dp);  
    }
    int countPartitions(vector<int>& arr, int d) {
        int totalsum = 0;
        for (int num : arr) {
            totalsum += num;
        }
        if (totalsum < d || (totalsum - d) % 2 != 0) {
            return 0;
        }
        int target = (totalsum - d) / 2;
        return solve(arr, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target); 
    }
};
