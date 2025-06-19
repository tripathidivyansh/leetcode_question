class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, int index) {
        if (path.size() >= 2) {
            ans.push_back(path);
        }
        unordered_set<int> s; 
        for (int i = index; i < nums.size(); i++) {
            if ((path.empty() || nums[i] >= path.back()) && s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
                path.push_back(nums[i]);
                solve(nums, ans, path, i + 1);
                path.pop_back(); 
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(nums, ans, path, 0);
        return ans;
    }
};
