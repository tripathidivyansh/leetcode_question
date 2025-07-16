class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evencount = 0, oddcount = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) {
                evencount++;
            } else {
                oddcount++;
            }
        }
        int parity = nums[0] % 2;
        int alternatingparity = 1;
        for(int i = 1; i < n; i++) {

            int currparity = nums[i] % 2;
            if(currparity != parity) {
                alternatingparity++;
                parity = currparity;
            }
        }

        int maxi = max(oddcount, max(evencount, alternatingparity));

        return maxi;
    }
};