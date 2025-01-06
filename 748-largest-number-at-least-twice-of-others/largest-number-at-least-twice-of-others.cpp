class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN;
        int maxIndex = -1;

        for(int i = 0; i<n; i++){
            if(maxVal < nums[i]){
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        for(int i = 0; i<n; i++){
            if(i != maxIndex &&maxVal < 2*nums[i]){
                return -1;
            }
        }
        return maxIndex;
    }
};