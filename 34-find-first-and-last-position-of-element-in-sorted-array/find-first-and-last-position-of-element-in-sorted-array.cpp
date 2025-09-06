// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int>anS = {-1, -1};

//         for(int i = 0; i<n; i++){
//             if(nums[i] == target){
//                 if(anS[0] == -1){
//                     anS[0] = i;
//                 }
//                 anS[1] = i;
//             }
//         }
//         return anS;
//     }
// };
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int>reSult = {-1, -1};
        int l = 0, r = nums.size()-1;
        while(l <=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                reSult[0] = mid;
                r = mid-1;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        
        l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                reSult[1] = mid;
                l = mid+1;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return reSult;
    }
};



