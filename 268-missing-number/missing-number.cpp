class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int Sum = n*(n+1)/2, Sum1 = 0;

        for(int i = 0; i<nums.size(); i++){
            Sum1 += nums[i];
        } 
        return Sum - Sum1;
    }
};