class Solution {
public:
    int SolveAlice(int perSon, int i, int m, vector<int>&piles, vector<vector<vector<int>>>&dp){
        int n = piles.size();
        if(i >= n) return 0;

        if(dp[perSon][i][m] != -1) return dp[perSon][i][m];

        long long reSult = (perSon == 1) ? -1 : INT_MAX;
        int Stones = 0;

        for(int x = 1; x <= min(2*m, n - i); x++){
            Stones += piles[i + x - 1];
            if(perSon == 1){
                reSult = max(reSult, (long long)Stones + SolveAlice(0, i + x, max(m, x), piles, dp));
            }else{
                reSult = min(reSult, (long long)SolveAlice(1, i + x, max(m, x), piles, dp));
            }
        } 

        return dp[perSon][i][m] = (int)reSult;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return SolveAlice(1, 0, 1, piles, dp);
    }
};

























