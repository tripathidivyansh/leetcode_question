class Solution {
public:
    void Solve(int index, vector<vector<int>>&reSult, vector<int>path, vector<int>&nums){
        if(index >= nums.size()){
            reSult.push_back(path);
            
            return;
        }
        path.push_back(nums[index]);
        Solve(index+1, reSult, path, nums);
        path.pop_back();
        Solve(index+1, reSult, path, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>reSult;
        vector<int>path;

        Solve(0, reSult, path,  nums);
        return reSult;
    }
};