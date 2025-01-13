class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // int n = nums.size();
        // int maxi = INT_MIN;
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         if(nums[i] == -nums[j]){
        //             maxi = max(maxi, nums[i]);
        //         }
        //     }
        // }
        // if(maxi == INT_MIN){
        //     return -1;
        // }
        // return maxi;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        int maxi = -1;

        while(left < right){
            if(nums[right] == - nums[left]){
                maxi = max(maxi, nums[right]);
                left++;
                right--;
            }else if(nums[right] > -nums[left]){
                right--;
            }else{
                left++;
            }
        }
        return maxi;
    }
};