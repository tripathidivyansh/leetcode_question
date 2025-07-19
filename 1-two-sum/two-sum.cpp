class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            
            int remaingng = target - nums[i];
            if(mp.find(remaingng) != mp.end()){
                return {mp[remaingng], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};