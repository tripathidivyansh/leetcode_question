class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int start = 0, currSum = 0, maxSum = 0;

        for (int end = 0; end < nums.size(); ++end) {
            while (seen.count(nums[end])) {
                seen.erase(nums[start]);
                currSum -= nums[start];
                start++;
            }
            seen.insert(nums[end]);
            currSum += nums[end];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};