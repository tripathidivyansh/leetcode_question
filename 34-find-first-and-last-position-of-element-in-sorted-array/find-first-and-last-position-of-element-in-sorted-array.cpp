// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> result = {-1, -1};
//         for(int i = 0; i<n; i++){
//             if(nums[i] == target){
//                 if(result[0] == -1){
//                     result[0] = i;
//                 }
//                 result[1] = i;
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int n = nums.size();

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
