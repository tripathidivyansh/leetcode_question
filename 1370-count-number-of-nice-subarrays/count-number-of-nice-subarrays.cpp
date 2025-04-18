class Solution {
public:

    int solve(vector<int>&nums, int k){
        int l = 0, r= 0, count = 0;
        int odd = 0;

        while(r < nums.size()){
            if(nums[r] % 2 != 0){
                odd ++;
            }
            while(odd > k){
                if(nums[l] % 2 != 0){
                    odd--;
                }
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        return solve(nums, k) - solve(nums, k-1);
    }
};