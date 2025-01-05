class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            bool found = false;
            for(int j = 0;j<n; j++){
                if(nums[j] == original){
                    original *= 2;
                    found = true;
                    break;
                }
            }
            if(!found){
                break;
            }
        }
        return original;
    }
};