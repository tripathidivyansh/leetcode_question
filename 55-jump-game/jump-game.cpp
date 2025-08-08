class Solution {
public:
    bool solve(vector<int>&nums){
        int maxindex = 0;
        for(int i = 0; i<nums.size(); i++){

            if(i > maxindex){
                return false;
            }
            maxindex = max(maxindex, i + nums[i]);
        }
        return true;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums);
    }
    
};