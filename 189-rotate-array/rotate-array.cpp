class Solution {
public:
    void reverses(vector<int>& nums, int low, int high){
        while(low<=high){
            int temp = nums[high];
            nums[high] = nums[low];
            nums[low] = temp;
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        int low = 0;
        int high = nums.size()-1;
        reverses(nums,  0, n-k-1);
        reverses(nums, n-k, n-1);
        reverses(nums, 0, n-1);
    }
};