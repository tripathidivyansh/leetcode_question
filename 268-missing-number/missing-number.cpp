class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int xor1 = 0, xor2 = 0;
        // for(int i = 0; i<n; i++){
        //     xor2 ^= nums[i];
        // }
        // for(int i = 1; i<=n; i++){
        //     xor1 ^= i;
        // }
        // return (xor1 ^ xor2);

        int sum = n*(n+1)/2;
        int sum1 = 0;

        for(int i = 0; i<n; i++){
            sum1+= nums[i];
        }
        int ans = sum-sum1;
        return ans;
    }
};