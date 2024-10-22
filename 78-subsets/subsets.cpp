class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0; i<(1<<n); i++){
            vector<int>sub;
            for(int j =0; j<n; j++){
                if(i & (1<<j))sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }
};

// class Solution {
// public:
//     void helper(int i, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
//         if (i == nums.size()) {
//             ans.push_back(current);
//             return;
//         }
//         helper(i + 1, nums, current, ans);
//         current.push_back(nums[i]);
//         helper(i + 1, nums, current, ans);
//         current.pop_back();
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> current;
//         helper(0, nums, current, ans);
//         return ans;
//     }
// };
