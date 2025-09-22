class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int left = 0, cnt = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == mx) cnt++;

            while (cnt >= k) {
                if (nums[left] == mx) cnt--;
                left++;
            }
            ans += left; 
        }
        return ans;
    }
};

