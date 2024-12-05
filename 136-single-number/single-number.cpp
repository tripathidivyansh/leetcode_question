class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int unique = 0;
        for(int i = 0; i<n; i++){
            unique ^= nums[i];
        }
        return unique;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>mp;
//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         for(auto &num : mp){
//             if(num.second == 1){
//                 return num.first;
//             }
//         }
//         return -1;
//     }
// };