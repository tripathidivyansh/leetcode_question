class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int Sum = 0, len = INT_MAX;

        while(r < nums.size()){
            Sum += nums[r];
            while(Sum >= target){
                len = min(len, r-l+1);
                Sum -= nums[l];
                l++;
            }
            r++;
        }
        if(len == INT_MAX) return 0;
        
        return len;
    }
};