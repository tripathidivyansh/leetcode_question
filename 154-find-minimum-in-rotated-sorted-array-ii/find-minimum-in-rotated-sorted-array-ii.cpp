class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int min = INT_MAX;
        for(int i = 0; i<n; i++){
            if(nums[i] < min){
                min = nums[i];
            }
        }
        return min;





        
        // int low = 0, high = nums.size()-1;
        // while(low < high){
        //     int mid = (low+high)/2;
        //     if(nums[mid] > nums[high]){
        //         low = mid+1;
        //     }else if(nums[mid] < nums[high]){
        //         high = mid;
        //     }else{
        //         high--;
        //     }
        // }
        // return nums[low];      
    }

};