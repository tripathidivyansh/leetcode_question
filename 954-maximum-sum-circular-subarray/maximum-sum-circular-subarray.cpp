class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int currmax = 0, maxSum = nums[0];
        
        int currmin = 0, minSum = nums[0];
        int total = 0;
        for(int i = 0; i<n; i++){
            int num = nums[i];
            total += num;
            currmax = max(num, currmax + num);
            maxSum = max(maxSum, currmax);
            currmin = min(num, currmin + num);
            minSum = min(minSum, currmin);
        }
        
        if(maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};
