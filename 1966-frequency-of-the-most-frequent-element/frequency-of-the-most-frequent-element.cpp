class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long Sum = 0;
        int l = 0, reS = 1;
        for(int r = 0; r < nums.size(); r++){
            Sum += nums[r];
            while ((long long )nums[r] * (r - l + 1) - Sum > k) {
                Sum -= nums[l];
                l++;
            }   
            reS = max(reS, r - l + 1);
        }

        return reS;
    }
};

