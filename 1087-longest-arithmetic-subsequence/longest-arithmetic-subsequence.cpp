class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        int ans = 2;
        vector<unordered_map<int,int>>dp(n);
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i]-nums[j];

                if(dp[j].count(diff)){
                    dp[i][diff] = dp[j][diff] + 1;
                }else{
                    dp[i][diff] = 2;
                }
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};