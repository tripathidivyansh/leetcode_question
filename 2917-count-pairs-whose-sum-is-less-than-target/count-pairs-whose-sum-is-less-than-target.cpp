// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target) {

//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i<n-1; i++){
//             for(int j = i+1; j<n; j++){
//                 if(nums[i] + nums[j] < target){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int i =0 ;
        int j = n-1;

        while(i <j){
            if(nums[i] + nums[j] < target){
                count+= (j-i);
                i++;
            }else{
                j--;
            }
        }
        return count;
    }
};
