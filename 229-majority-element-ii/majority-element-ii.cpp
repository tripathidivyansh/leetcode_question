class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto num : mp){
            if(num.second > n/3){
                ans.push_back(num.first);
            }
        }
        return ans;
    }
};