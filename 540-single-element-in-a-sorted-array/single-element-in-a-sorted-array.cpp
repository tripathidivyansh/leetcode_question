class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];
        }

        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }

        int low = 1,high = nums.size() - 2;
        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            
            if((mid % 2 == 1 && nums[mid-1] == nums[mid]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1])){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
        // int n = nums.size();
        // unordered_map<int,int>mp;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        // }
        // for(auto &num : mp){
        //     if(num.second == 1){
        //         return num.first;
        //     }
        // }
        // return -1;
