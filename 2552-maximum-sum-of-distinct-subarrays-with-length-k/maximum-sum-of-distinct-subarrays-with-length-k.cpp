class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0;  
        long long Sum = 0, maxSum = 0;

        unordered_map<int,int> mp;
        while(r < nums.size()) {
            mp[nums[r]]++;
            Sum += nums[r];

            if(r - l + 1 > k) {
                mp[nums[l]]--;
                Sum -= nums[l];
                if(mp[nums[l]] == 0) {
    
                    mp.erase(nums[l]);
                }
                l++;
            }

            if((r - l + 1 == k) && (mp.size() == k)) {
                maxSum = max(maxSum, Sum);
            }

            r++;
        }
        return maxSum;
    }
};
