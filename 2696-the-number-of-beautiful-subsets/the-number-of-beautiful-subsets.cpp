class Solution {
public:

    void solve(vector<int>&nums, int index, unordered_map<int,int>&mp, int k, int &result){
        if(index >= nums.size()){

            if(!mp.empty()){
                result++;
                return;
            }
        }
        if(mp[nums[index] - k] == 0 && mp[nums[index] + k] == 0){
            mp[nums[index]]++;
            solve(nums, index+1, mp, k, result);
            mp[nums[index]]--;
        }
        solve(nums, index+1, mp, k, result);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int result = 0;

        solve(nums, 0, mp, k, result);
        return result-1;
    }
};