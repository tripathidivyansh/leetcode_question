class Solution {
public:
    int findGCD(vector<int>& nums) {
        int miniE = *min_element(nums.begin(), nums.end());
        int maxE = *max_element(nums.begin(), nums.end());
        return __gcd(miniE, maxE);
    }
};
