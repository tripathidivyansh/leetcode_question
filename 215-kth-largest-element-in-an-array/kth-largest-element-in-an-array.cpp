class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int>pq;
        for(int i = 0; i<nums.size(); i++){
            pq.push(nums[i]);
            // if(pq.size() > k){
            //     pq.pop();
            // }
        }
        for(int i = 1; i<k; i++){
            pq.pop();
        }
        return pq.top();
    }
};