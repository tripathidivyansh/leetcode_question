class Solution {
public:
    void solve(int index, vector<int>&ds, vector<int>&nums, vector<vector<int>>&result){
        if(index == nums.size()){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(index+1, ds, nums, result);
        ds.pop_back();

        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        solve(index+1, ds, nums, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       
        vector<vector<int>>result;
        vector<int>ds;
          sort(nums.begin(), nums.end());
        solve(0, ds, nums, result);
      
        return result;
    }
};