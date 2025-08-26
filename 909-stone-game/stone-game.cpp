class Solution {
public:
    int Solve(int i, int j, vector<int>&piles, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];
        int take_i = piles[i] + min(Solve(i+2, j, piles, dp), Solve(i+1, j-1, piles, dp));
        int take_j = piles[j] + min(Solve(i, j-2, piles, dp), Solve(i+1, j-1, piles, dp));
        return dp[i][j] =  max(take_i, take_j);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int firSt = Solve(0, n-1, piles, dp);
        int Second = totalSum - firSt;
        if(firSt >= Second){
            return true;
        }
        return false;
    }
};