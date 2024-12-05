class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0, left_sum = 0;

        for(int i = 0; i<n; i++){
            total_sum+= nums[i];
        }
        for(int i = 0; i<n; i++){
            if(left_sum == total_sum-left_sum-nums[i]){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};