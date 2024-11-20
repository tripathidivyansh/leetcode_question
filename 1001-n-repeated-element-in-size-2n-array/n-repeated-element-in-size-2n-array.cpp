// class Solution {
// public:
//     int repeatedNTimes(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>mp;
//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         for(auto entry : mp){
//             if(entry.second== n/2){
//                 return entry.first;
                
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
            if(count == n / 2) {
                return nums[i];
            }
        }
        return -1;
    }
};



