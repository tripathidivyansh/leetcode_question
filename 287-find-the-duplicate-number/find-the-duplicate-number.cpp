class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        int count = 1;
        for(auto num : mp){
            if(num.second > 1){
                return num.first;
            }
        }
        return -1;
    }
};