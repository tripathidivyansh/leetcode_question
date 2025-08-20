class Solution {
public:
    long long findcoSt(vector<int>& nums, vector<int>& cost, int target) {
        long long reSult = 0;
        for (int i = 0; i < nums.size(); i++) {
            reSult += (long long)abs(nums[i] - target) * cost[i];
        }
        return reSult;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        long long ans = LLONG_MAX;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long cost1 = findcoSt(nums, cost, mid);
            long long cost2 = findcoSt(nums, cost, mid + 1);

            ans = min(ans, min(cost1, cost2));  

            if (cost1 > cost2) {
                left = mid + 1;  
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

