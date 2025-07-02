class Solution {
public:
    void solve(vector<int>& nums, unordered_map<int, int>& mp, vector<int>& temp, vector<vector<int>>& result) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);

            return;
        }
        for(auto& [num, count] : mp) {
            if(count == 0) continue;

            temp.push_back(num);
            mp[num]--;
            solve(nums, mp, temp, result);
            temp.pop_back();
            mp[num]++;
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> result;

        for(int num : nums) {
            mp[num]++;
        }

        vector<int> temp;
        solve(nums, mp, temp, result);
        return result;
    }
};
