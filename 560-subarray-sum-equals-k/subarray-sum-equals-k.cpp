class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;  // handles case when subarray starts from index 0
        int sum = 0, count = 0;

        for(int num : nums) {
            sum += num;
            if(prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }
            prefixSum[sum]++;
        }
        return count;
    }
};
