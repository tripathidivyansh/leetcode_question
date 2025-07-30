class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxlen = 0;
        int maxele = 0;
        for(int num : nums){
            if(num > maxele){
                maxele = num;
                count = 1;
                maxlen = 1;
            }else if(num == maxele){
                count++;
                maxlen = max(maxlen, count);
            }else{
                count = 0;
            }
        }
        return maxlen;
    }
};