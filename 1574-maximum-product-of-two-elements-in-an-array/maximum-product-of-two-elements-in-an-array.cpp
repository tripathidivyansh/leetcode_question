class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int n = nums.size();
        // int max1 = INT_MIN, max2 = INT_MIN;
        // for(int i = 0; i<n; i++){
        //     if(nums[i] > max1){
        //         max2 = max1;
        //         max1 = nums[i];
        //     }else if(nums[i] > max2){
        //         max2 = nums[i];
        //     }
        // }
        // return (max1-1)*(max2-1);

        priority_queue<int>pq;
        // for(int num:nums){
        //     pq.push(num);
        // }
        int n = nums.size();
        for(int i = 0; i<n; i++){
            pq.push(nums[i]);
        }
        int max1 = pq.top();
        pq.pop();
        int max2 = pq.top();

        return (max1-1) * (max2-1);
    }
};