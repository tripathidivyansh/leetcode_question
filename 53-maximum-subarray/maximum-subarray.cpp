class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MIN;
        while(j < nums.size()){
            sum += nums[j];
            j++;
            len = max(len, sum);
            if(sum <= 0){
                sum = 0;
            }
        }
        return len;
    }
};