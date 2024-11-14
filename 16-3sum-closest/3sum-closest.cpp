// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//         int n = nums.size();
//         int ans = INT_MAX;

//         sort(nums.begin(), nums.end());
//         for(int i = 0; i<n-2; i++){
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
//             int j = i+1;
//             int k = n-1;

//             while(j < k){
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if(abs(target-sum) < abs(target-ans)){
//                     ans = sum;
//                 }
//                 if(sum < target){
//                     j++;
//                 }else if(sum > target){
//                     k--;
//                 }else{
//                     return ans;
//                 }
//             } 
//         }
//         return ans;     
//     }
// };

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        
        // If there are fewer than 3 numbers, it's impossible to find a triplet
        if (n < 3) return 0; 

        // Initialize the answer to a large number or use the sum of the first triplet
        int ans = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // Skip the same element to avoid redundant calculations
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Update answer if this sum is closer to the target
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }

                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    return sum;  // If we find the exact target, return the sum
                }
            }
        }
        return ans;  // Return the closest sum found
    }
};
