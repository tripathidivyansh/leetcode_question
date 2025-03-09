class Solution {
public:
    void solve(int index, vector<int>&ds,vector<int>&nums, vector<vector<int>>&result){
        if(index == nums.size()){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(index+1, ds, nums, result);
        ds.pop_back();

        solve(index+1, ds, nums, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>ds;
        solve(0, ds, nums, result);
        return result;
    }
};