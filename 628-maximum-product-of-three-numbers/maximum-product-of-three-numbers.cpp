class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // int product = 1;
        // for(int i = 0; i<n; i++){
        //     product *= nums[i];
        // }
        // return product;
        return max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);    
    }
};