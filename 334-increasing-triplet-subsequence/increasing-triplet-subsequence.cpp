class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        // for(int i = 0; i<n-2;i++){
        //     for(int j =i+1; j<n-1; j++){
        //         for(int k = j+1; k<n; k++){
        //             if(nums[i] < nums[j] && nums[j] < nums[k]){
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        int first = INT_MAX, second = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i] <= first){
                first = nums[i];
            }else if(nums[i] <= second){
                second = nums[i];
            }else{
                return true;
            }
        }
        return false;
    }
};