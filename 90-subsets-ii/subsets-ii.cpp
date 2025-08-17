class Solution {
public:
    void Solve(int index, vector<int>&nums, vector<vector<int>>&reSult, vector<int>&path){
        if(index >= nums.size()){
            reSult.push_back(path);

            return;
        }
        path.push_back(nums[index]);
        Solve(index+1, nums, reSult, path);
        while(index + 1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        path.pop_back();
        Solve(index+1, nums, reSult, path);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>reSult;
        vector<int>path;
        sort(nums.begin(), nums.end());

        Solve(0, nums, reSult, path);
        return reSult;
    }

};





