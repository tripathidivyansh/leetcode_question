class Solution {
private:
    void perm(int pos, vector<int> &nums, vector<vector<int>> &ans) {
        if (pos >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[i], nums[pos]);
            perm(pos + 1, nums, ans);
            swap(nums[i], nums[pos]); // backtracking hai. ISSi ko back ttacking bolte hai malik
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        perm(0, nums, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
