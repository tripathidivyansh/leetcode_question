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
        for(int x = 0; x<=n; x++){
            int count = 0;
            for(int num : nums){
                if(num >= x){
                    count++;
                }
            }
            if(count == x){
                return x;
            }
        }
        return -1;
    }
};