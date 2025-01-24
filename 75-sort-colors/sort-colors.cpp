class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }

        // int low = 0, mid = 0, high = nums.size()-1;
        // while(mid <= high){
        //     if(nums[mid] == 0){
        //         swap(nums[low], nums[mid]);
        //         low++;
        //         mid++;
        //     }else if(nums[mid] == 1){
        //         mid++;
        //     }else{
        //         swap(nums[mid], nums[high]);
        //         high--;
        //     }
        // }

    }
};