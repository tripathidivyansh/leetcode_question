class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto malik : mp){
            if(malik.second == 1){
                sum+= malik.first;
            }
        }
        return sum;
    }
};