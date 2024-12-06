// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int,int>mp;
//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         int count = 1;
//         for(auto num : mp){
//             if(num.second > 1){
//                 return num.first;
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = nums.size()-1;

        while(low < high){
            int count = 0;
           int mid = (low+high)/2;
           for(int num : nums){
            if(num <= mid){
                count++;
            }
           } 
           if(count > mid){
            high = mid;
           }else{
            low = mid+1;
           }
        }
        return low;
    }
};