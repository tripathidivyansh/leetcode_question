class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>result;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto num : mp){
            if(num.second > 1){
                result.push_back(num.first);
            }
        }
        return result;
    }
};