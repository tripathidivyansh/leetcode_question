class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>temp(n);

        k = k %n;
        for(int i = 0; i<k; i++){
            temp[i] = nums[n-k+i];
        }
        for(int i = 0; i<n-k; i++){
            temp[k+i] = nums[i];
        }
        for(int i = 0; i<n; i++){
            nums[i] = temp[i];
        }
        // reverse(nums.begin(), nums.end());

        // reverse(nums.begin(), nums.begin() + k);
        // reverse(nums.begin() + k, nums.end());
    }
    
};









