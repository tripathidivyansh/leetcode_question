class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long badPair = 0;
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[j] - nums[i] != j-i){
        //             count++;
        //         }
        //     }
        // }
        // return count;
        unordered_map<int,int>mp;
        for(int i = 0; i<nums.size(); i++){
            int diff = i-nums[i];
            int good = mp[diff];
            badPair += i-good;

            mp[diff] = good+1;
        }
        return badPair;
    }
};