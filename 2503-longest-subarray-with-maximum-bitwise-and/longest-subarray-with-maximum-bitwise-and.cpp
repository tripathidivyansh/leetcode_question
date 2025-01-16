class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxlen = 0;
        int maxele = 0;
        for(int i = 0; i<n; i++){
            maxele = max(maxele, nums[i]);
        }
        for(int i = 0; i<n; i++){
            if(nums[i] == maxele){
                count++;
                maxlen = max(maxlen, count);
            }else{
                count = 0;
            }
        }
        return maxlen;
    }
};