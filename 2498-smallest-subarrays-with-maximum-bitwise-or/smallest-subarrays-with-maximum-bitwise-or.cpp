class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        vector<int> lastSeen(32, -1); 
        for (int i = n - 1; i >= 0; i--) {
            for (int b = 0; b < 32; b++) {
                if ((nums[i] >> b) & 1) {
                    lastSeen[b] = i;  
                }
            }
            int maxPos = i;
            for (int b = 0; b < 32; b++) {
                if (lastSeen[b] != -1) {
                    maxPos = max(maxPos, lastSeen[b]);
                }
            }
            res[i] = maxPos - i + 1;
        }
        return res;
    }
};