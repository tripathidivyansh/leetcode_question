class Solution {
public:
    int findMin(vector<int>& nums) {
        // int mini = nums[0];
        // for(int i : nums) mini = min(mini, i);
        // return mini;

        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        int low = 0,  high = nums.size()-1;
        while(low < high){
            int mid = (low + high) / 2;
            if(nums[mid] < nums[high]){
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return nums[low];  

        // int min = nums[0];
        // for(int i = 0; i<n; i++){
        //     if(nums[i] < min){
        //         min = nums[i];
        //     }
        // }
        // return min;
    }
};