class Solution {
public:

    void solve(int index, vector<int>&nums, set<vector<int>>&result){
        if(index >= nums.size()){
            result.insert(nums);
            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(index+1, nums, result);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>result;
        solve(0, nums, result);

        return vector<vector<int>>(result.begin(), result.end());
    }
};