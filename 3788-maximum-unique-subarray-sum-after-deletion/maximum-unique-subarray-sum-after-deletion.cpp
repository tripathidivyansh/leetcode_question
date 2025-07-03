class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int Sum = nums[nums.size()-1];

        for(int i = nums.size()-2; i>= 0; i--){
            if(nums[i] != nums[i+1]){
                if(Sum < Sum + nums[i]){
                    Sum += nums[i];
                }else{
                    break;
                }
            }
        }
        return Sum;

    }
};