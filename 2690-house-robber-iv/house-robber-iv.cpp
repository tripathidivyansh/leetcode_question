class Solution {
public:
    int iSPOSSIBle(vector<int>&nums, int mid, int k){
        int houSe = 0;
        for(int i = 0; i<nums.size(); i++){
            
            if(nums[i] <= mid){
                houSe++;
                i++;
            }
        }
        return houSe >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = *min_element(nums.begin(), nums.end());

        int r = *max_element(nums.begin(), nums.end());
        int reSult = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(iSPOSSIBle(nums, mid, k) == true){
                reSult = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return reSult;
    }
};
// dp Soln
// class Solution {
// public:
//     int Solve(int index, vector<int>&nums, int k, vector<vector<int>>&dp){
//         if(k == 0) return 0;
//         if(index >= nums.size()) return INT_MAX;

//         if(dp[index][k] != -1) return dp[index][k];
//         int take = max(nums[index], Solve(index+2, nums, k-1, dp));
//         int nottake = Solve(index+1, nums, k, dp);
//         // return min(take, nottake);
//         return dp[index][k] = min(take, nottake);
//     }
//     int minCapability(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
//         return Solve(0, nums, k, dp);
//     }
// };


