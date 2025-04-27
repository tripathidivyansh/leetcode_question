class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0, maxlen = 0;
        int l = 0, r = 0;

        while(r < nums.size()){
            if(nums[r] == 1){
                count++;
                maxlen = max(maxlen, count);
            }else{
                count = 0;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};