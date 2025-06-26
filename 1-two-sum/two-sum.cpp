class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        int Sum = 0;

        int n = nums.size();
        for(int i = 0; i<n; i++){
            int Sum  = target-nums[i];
            if(mp.find(Sum) != mp.end()){
                return {mp[Sum], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};