class Solution {
public:

    void solve(vector<vector<int>>&nums, int &Sum){
        int n = nums.size();
        int m = nums[0].size();

        for(int i = 0; i<n; i++){
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }
        for(int j = 0; j<m; j++){
            int maxi = INT_MIN;
            for(int i = 0; i<n; i++){
                maxi = max(maxi, nums[i][j]);
            }
            Sum += maxi;
        }
    }
    int matrixSum(vector<vector<int>>& nums) {
        int Sum = 0;
        solve(nums, Sum);
        return Sum;
    }
};