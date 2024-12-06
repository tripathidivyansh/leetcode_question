class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        vector<int>result;
        for(auto num : mp){
            if(num.second == 1){
                result.push_back(num.first);
            }
        }
        return result;
    }
};