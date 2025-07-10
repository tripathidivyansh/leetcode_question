class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto & malik : mp){
            if(malik.second == 1){
                return -1;
            }
            ans += ceil((double)malik.second / 3);

        }

        return ans;
    }
};