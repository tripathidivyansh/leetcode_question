class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total_sum = 0;
        long long left_sum = 0;
        long long count = 0;
        for(int i = 0; i<n; i++){
            total_sum += nums[i];
        }
        for(int i = 0; i<n-1; i++){
            left_sum += nums[i];
            long long right_sum = total_sum-left_sum;
            if(left_sum >= right_sum){
                count++;
            }
        }
        return count;
    }
};