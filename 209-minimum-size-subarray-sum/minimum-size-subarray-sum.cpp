class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r= 0;
        int Sum = 0, len = INT_MAX, len1 = INT_MAX;

        while(r < nums.size()){
            Sum += nums[r];
            while(Sum >= target){
                len = min(len, r-l+1);
                Sum -= nums[l];
                l++;
            }
            r++;
            len1 = min(len1, len);
        }

        if(len1 == INT_MAX) return 0;
        return len1;
    }
};