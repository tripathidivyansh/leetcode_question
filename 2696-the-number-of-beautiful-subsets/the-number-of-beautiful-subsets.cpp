class Solution {
public:
    void solve(int index, vector<int>& nums, unordered_map<int,int>& mp, int& result, int k) {
        if(index >= nums.size()) {
            result++; 

            return;
        }        
        if(mp[nums[index] - k] == 0 && mp[nums[index] + k] == 0) {
            mp[nums[index]]++;
            solve(index + 1, nums, mp, result, k);
            mp[nums[index]]--;
        }
        solve(index + 1, nums, mp, result, k);
    }
    int beautifulSubsets(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        int result = 0;
        solve(0, nums, mp, result, k);
        return result-1;
        // empty subset is also calculate that way we reduce the time complexity.
        // or change the baSe caSe where if(!mp.empty()){
            //result ++;
        //}
    }
};
