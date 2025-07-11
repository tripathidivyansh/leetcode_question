class Solution {
public:
    void solve(int index, vector<int>&nums, vector<vector<int>>&result, vector<int>&path){
        if(index >= nums.size()){
            result.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        solve(index+1, nums, result, path);
        path.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        // path.pop_back();
        solve(index+1, nums, result, path);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>path;

        sort(nums.begin(), nums.end());
        solve(0, nums, result, path);
        return result;
    }
};