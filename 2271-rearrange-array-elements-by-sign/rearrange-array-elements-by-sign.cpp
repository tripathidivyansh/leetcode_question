class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        vector<int>v;
        while(i < n && j < n){
            while(i<n && nums[i] < 0){
                i++;
            }
            if(i < n){
                v.push_back(nums[i]);
                i++;
            }
            while(j < n && nums[j] >= 0){
                j++;
            }
            if(j < n){
                v.push_back(nums[j]);
                j++;
            }
        }
        return v;
    }
};