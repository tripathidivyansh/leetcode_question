class Solution {
public:
    int specialArray(vector<int>& nums) {
        // int n = nums.size();
        // int count = 0;
        // for(int i = 0; i<=n; i++){
        //     count++;
        // }
        // for(int i = 0; i<n; i++){
        //     if(count == n && nums[i] >= count){
        //         return count;
        //     }
        // }
        // return -1;
        int n = nums.size();
        for(int i = 0; i<=n; i++){
            int count = 0;
            for(int num : nums){
                if(num >= i){
                    count++;
                }
            }
            if(count == i){
                return i;
            }
        }
        return -1;
    }
};