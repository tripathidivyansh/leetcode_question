// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int, vector<int>, greater<int>>pq;
//         for(auto x: nums){
//             pq.push(x);
//             if(pq.size() > k){
//                 pq.pop();
//             }
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};




// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         priority_queue<int>pq(nums.begin(), nums.end());

//         int ans = 0;
//         while(k--){
//             ans = pq.top();
//             pq.pop();
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         return nums[n-k];
//     }
// };