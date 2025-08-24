class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, count = 0, maxcount = 0;

        while(r < nums.size()){
            if(nums[r] == 0){
                count++;
            }
             while (count > 1) { 
                if (nums[l] == 0) count--; 
                l++;  
            }
            maxcount = max(maxcount, r - l); 
            r++;
        }
        return maxcount;
    }
};

