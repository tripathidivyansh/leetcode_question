class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxindex = 0;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > nums[maxindex]){
                maxindex = i;
            }
        }
        return maxindex;
    }
};









