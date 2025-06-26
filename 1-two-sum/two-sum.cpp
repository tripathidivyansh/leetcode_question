class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // int Sum = INT_MIN;

        for(int i = 0; i<n-1; i++){
            int Sum = 0;
            for(int j = i+1; j<n; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }      
            }
        }
        return {};
    }
};