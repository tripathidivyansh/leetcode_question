class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int Sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }
        while(k > 0){
            Sum += maxi;
            maxi++;
            k--;
        }
        return Sum;
    }
};