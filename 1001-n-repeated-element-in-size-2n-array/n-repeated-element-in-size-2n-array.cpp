class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto entry : mp){
            if(entry.second== n/2){
                return entry.first;
                
            }
        }
        return -1;
    }
};



