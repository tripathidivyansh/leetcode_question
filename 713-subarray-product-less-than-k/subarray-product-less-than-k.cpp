class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1){
            return 0;
        }
        long long count = 0, product = 1;
        int l = 0, r = 0;
        while(r < nums.size()){
            product *= nums[r];
            while(product >= k && l<=r){
                product /= nums[l];
                l++;
            }
            count += (r-l+1);

            r++;
        }
        return count;
    }
};