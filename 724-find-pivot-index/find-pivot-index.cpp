// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         int sum1 = 0;
//         for(int i = 0; i<n; i++){
//             int sum += nums[i];
//             for(int j = n-1; j>= 0; j--){
//                 sum1+= nums[j];

//                 if(sum == sum1){
//                     break;
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0, left_sum = 0;

        for(int i = 0; i<n; i++){
            total_sum += nums[i];
        }
        for(int i = 0; i<n; i++){
            if(left_sum == total_sum - left_sum - nums[i]){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};