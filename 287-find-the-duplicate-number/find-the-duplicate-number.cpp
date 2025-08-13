class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());

        // for(int i = 0; i<n; i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        
        for(auto &malik : mp){
            if(malik.second > 1){
                return malik.first;
            }
        }
        return -1;
    }
};









































































