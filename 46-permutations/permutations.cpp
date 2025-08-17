class Solution {
public:
    void Solve(int index, vector<int>&nums, vector<vector<int>>& reSult){
        if(index >= nums.size()){
            reSult.push_back(nums);

            return;
        }
        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            Solve(index+1, nums, reSult);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>reSult;

        Solve(0, nums, reSult);
        return reSult;
    }
};
