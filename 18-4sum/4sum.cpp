class Solution {
public:
    void twoSum(vector<int>& nums, long long  target, int i, int j, int n1, int n2, vector<vector<int>>& result) {
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum < target) {
                i++;
            } else if (sum > target) {
                j--;
            } else {
                result.push_back({n1, n2, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, long long  target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long  newTarget = target - nums[i] - nums[j];
                twoSum(nums, newTarget, j + 1, n - 1, nums[i], nums[j], result);
            }
        }

        return result;
    }
};