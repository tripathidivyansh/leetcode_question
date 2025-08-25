class Solution {
public:
    bool Solve(int curr_index, int prevjump, vector<int>&stones, unordered_map<int,int>&mp, vector<vector<int>>&dp){
        if(curr_index >= stones.size() - 1) return true;
        bool reSult = false;

        if(dp[curr_index][prevjump] != -1) return dp[curr_index][prevjump];
        for(int nextjump = prevjump-1; nextjump <= prevjump+1; nextjump++){
            if(nextjump > 0){
              int nextStone =  stones[curr_index] + nextjump;
              if(mp.find(nextStone) != mp.end()){
                reSult = reSult ||  Solve(mp[nextStone], nextjump, stones, mp, dp);
              }
            }
        }
        dp[curr_index][prevjump] = reSult;
        return reSult;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,int>mp;
        
        if(stones[1] != 1) return false;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        for(int i = 0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }
        return Solve(0, 0, stones, mp, dp);
    }
};