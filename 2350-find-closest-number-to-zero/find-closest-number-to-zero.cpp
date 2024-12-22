class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closest = nums[0]; 
        for (int i = 1; i < n; i++) {
            if (abs(nums[i]) < abs(closest) || (abs(nums[i]) == abs(closest) && nums[i] > closest)) {
                closest = nums[i];
            }
        }
        return closest;
    }
};
