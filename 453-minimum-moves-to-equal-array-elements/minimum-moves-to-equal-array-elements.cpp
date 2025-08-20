class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int S = 0;
        // int mini = INT_MAX;

        // for(int i = 0; i<nums.size(); i++){
        //     S += nums[i];
        //     mini = min(mini, nums[i]);
        // }
        // return S - (mini * nums.size());
        sort(nums.begin(), nums.end());
        int moves = 0;
        for (int i = 1; i < nums.size(); i++) {
            moves += nums[i] - nums[0];
        }
        return moves;
    }
};