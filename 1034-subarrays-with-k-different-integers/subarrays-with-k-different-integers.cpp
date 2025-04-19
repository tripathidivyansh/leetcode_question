class Solution {
public:

    int solve(vector<int>&nums, int k){
        int l = 0, r = 0, count = 0, maxi = 0;
        vector<int>freq(100001, 0);
        while(r < nums.size()){
            if(freq[nums[r]] == 0){
                count++;
            }
            freq[nums[r]]++;
            while(count > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    count--;
                }
                l++;
            }
            maxi += (r-l+1);
            r++;
        }
        return maxi;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};