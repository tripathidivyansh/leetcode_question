class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // for(int i =0 ; i<n-1; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
        int target1 = target-nums[i];
        if(mp.find(target1) != mp.end()){
            return {mp[target1], i};
        }
        mp[nums[i]] = i;
        }
        return {};
    }
};


