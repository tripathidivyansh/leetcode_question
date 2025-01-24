// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();
//         int maxIndex = 0;
//         for(int i = 1; i < n; i++) {
//             if(nums[i] > nums[maxIndex]) {
//                 maxIndex = i; 
//             }
//         }
//         return maxIndex;
//     }
// };


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) /2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;        
    }
};
  
