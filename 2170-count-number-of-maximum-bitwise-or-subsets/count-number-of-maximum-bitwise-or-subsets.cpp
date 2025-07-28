class Solution {
public:
    int countSubset(int index, int currXor, vector<int>&nums, int maxXor){
        if(index == nums.size()){
            if(currXor == maxXor){
                return 1;
            }else{
                return 0;
            }
        }
        int take =  countSubset(index+1, currXor | nums[index], nums, maxXor);
        int nottake = countSubset(index+1, currXor, nums, maxXor);
        
        return take + nottake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxXor = 0;
        for(int &num : nums){
            maxXor |= num;
        }
        int currXor = 0;
        return countSubset(0, currXor, nums, maxXor);
    }
};