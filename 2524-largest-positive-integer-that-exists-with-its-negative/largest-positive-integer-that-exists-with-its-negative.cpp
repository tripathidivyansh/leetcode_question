class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(nums[i] == -nums[j]){
                    maxi = max(maxi, nums[i]);
                }
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        return maxi;
    }
};