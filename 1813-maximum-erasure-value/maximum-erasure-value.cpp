class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> S;
        int Sum = 0, maxSum = 0;
        int i = 0, j = 0;

        while (j < nums.size()) {
            if (!S.count(nums[j])) {
                Sum += nums[j];
                maxSum = max(maxSum, Sum);
                S.insert(nums[j]);
                j++;
            } else {
                while (i < nums.size() && S.count(nums[j])) {
                    Sum -= nums[i];        
                    S.erase(nums[i]);       
                    i++;                   
                }
            }
        }
        return maxSum;
    }
};
