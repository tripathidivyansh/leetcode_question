class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int maxsum = nums[0];
        int currsum = nums[0];

        for(int i  = 1; i<n; i++){
            if(nums[i-1] < nums[i]){
                currsum += nums[i];
                maxsum = max(maxsum, currsum);
            }else{
                currsum = nums[i];
            }
        }
        // maxsum = max(maxsum, currsum);
        return maxsum;
    }
};