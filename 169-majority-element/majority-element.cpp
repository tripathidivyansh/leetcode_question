class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        unordered_map<int,int>mp;
        for(int i =0; i<n; i++){
            mp[nums[i]]++;

            if(mp[nums[i]] > nums.size()/2){
                ans = nums[i];
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());
//         // int n = nums.size();
//         // return nums[n/2];

//         int count = 0;
//         int candidate = 0;

//         for(int num: nums){
//             if(count == 0){
//                 candidate = num;
//             }
//             if(num == candidate){
//                 count++;
//             }else{
//                 count--;
//             }
//         }
//         return candidate;

//         // int n = nums.size();
//         // for(int i = 0; i<n; i++){
//         //     int count = 0;
//         //     for(int j = 0; j<n; j++){
//         //         if(nums[i] == nums[j]){
//         //             count++;
//         //         }
//         //     }
//         //     if(count > n/2){
//         //         return nums[i];
//         //     }
//         // }
//         // return -1;
//     }

// };



// // class Solution {
// // public:
// //     int majorityElement(vector<int>& nums) {
// //         int count = 0;
// //         int candidate = 0;

// //         // First pass: Find the candidate
// //         for (int i = 0; i < nums.size(); i++) {
// //             if (count == 0) {
// //                 candidate = nums[i];
// //             }
// //             if (nums[i] == candidate) {
// //                 count++;
// //             } else {
// //                 count--;
// //             }
// //         }

// //         // Second pass: Verify that the candidate is indeed a majority
// //         count = 0;
// //         for (int i = 0; i < nums.size(); i++) {
// //             if (nums[i] == candidate) {
// //                 count++;
// //             }
// //         }

// //         // Check if the candidate appears more than n/2 times
// //         if (count > nums.size() / 2) {
// //             return candidate;
// //         } else {
// //             return -1;  // No majority element
// //         }
// //     }
// // };
