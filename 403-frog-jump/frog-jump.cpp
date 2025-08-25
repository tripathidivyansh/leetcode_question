class Solution {
public:
    bool Solve(int curr_index, int prevjump, vector<int>&stones, vector<vector<int>>&dp, unordered_map<int,int>&mp){
        if(curr_index >= stones.size()-1) return true;
        if(dp[curr_index][prevjump] != -1) return dp[curr_index][prevjump];
        
        bool result = false;
        for(int nextjump = prevjump-1; nextjump <= prevjump+1; nextjump++){
            if(nextjump > 0){
                int nextStone = stones[curr_index] + nextjump;
                if(mp.find(nextStone) != mp.end()){
                    result = result || Solve(mp[nextStone], nextjump, stones, dp, mp);
                }
            }
        }
        return dp[curr_index][prevjump] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return Solve(0, 0, stones, dp, mp);
    }
};


























