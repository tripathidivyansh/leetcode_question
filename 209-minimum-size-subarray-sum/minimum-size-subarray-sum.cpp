class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        // int left = 0;
        int length = INT_MAX;
        // for(int right = 0; right<n; right++){
        //     totalSum += nums[right];
        //     while(totalSum >= target){
        //         length = min(length, right - left + 1);
        //         totalSum -= nums[left];
        //         left++;
        //     }
        // }
        // if(length == INT_MAX){
        //     return 0;
        // }
        // return length;


        int i = 0;
        for(int j = 0; j<n; j++){
            totalSum += nums[j];
            while(totalSum >=target){
                length = min(length, j-i+1);
                totalSum -= nums[i];
                i++;
            }
        }
        if(length == INT_MAX){
            return 0;
        }
        return length;
    }
};
