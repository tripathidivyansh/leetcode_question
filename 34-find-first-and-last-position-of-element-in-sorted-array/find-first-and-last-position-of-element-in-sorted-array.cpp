class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result = {-1, -1};
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                if(result[0] == -1){
                    result[0] = i;
                }
                result[1] = i;
            }
        }
        return result;
    }
};