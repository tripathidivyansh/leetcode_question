class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        long long closetSum = INT_MAX;
        for(int k = 0; k < n-2; k++){
            int i = k+1, j = n-1;
            while(i < j){
                long long Sum = nums[i] + nums[j] + nums[k];
                if(abs(target - Sum ) < abs(target - closetSum)){
                    closetSum = Sum;
                }
                if(Sum < target){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return closetSum;
    }
};