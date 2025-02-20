class Solution {
public:
    int solve(int n, vector<vector<int>>&cuboids, int curr, int prev, vector<vector<int>>&dp){
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int maxheight = solve(n, cuboids, curr+1, prev, dp);

        if (prev == -1 || 
            (cuboids[curr][0] >= cuboids[prev][0] && 
             cuboids[curr][1] >= cuboids[prev][1] && 
             cuboids[curr][2] >= cuboids[prev][2])) {
            maxheight = max(maxheight, cuboids[curr][2] + solve(n, cuboids, curr + 1, curr, dp));
        }
        dp[curr][prev+1] = maxheight;
        return dp[curr][prev+1];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for (auto &cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end()); 
            
        }
        sort(cuboids.begin(),cuboids.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(n, cuboids, 0, -1, dp);
    }
};