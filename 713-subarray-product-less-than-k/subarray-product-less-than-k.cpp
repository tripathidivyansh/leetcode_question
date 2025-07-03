class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1){
            return 0;
        }
        long long product = 1;
        long long count = 0;
        int left = 0;
        int right = 0;
        while( right < n){
            product *= nums[right];

            while(product >= k && left <= right){
                product /= nums[left];
                left++;
            }
            count += right-left + 1;
            right++;
        }

        return count;
    }
};