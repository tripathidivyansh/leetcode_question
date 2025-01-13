class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mp[a] == mp[b]){
                return a > b;
            }
            return mp[a] < mp[b];
        });
        return nums;
    }
};