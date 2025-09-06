class Solution {
public:
    int findpivot(vector<int>&nums, int n){
        int l = 0, r = n-1;
        while(l < r){

            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;

    }
    int binarySearch(int l, int r, vector<int>&nums, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot_index = findpivot(nums, n);

        int ind = binarySearch(0, pivot_index-1, nums, target);
        if(ind != -1){
            return ind;
        }
        ind = binarySearch(pivot_index, n-1, nums, target);
        return ind;
    }
};


