class Solution {
public:
    int solve(int n, vector<int>&days, vector<int>&cost, int index, vector<int>&dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int optional1 = cost[0] + solve(n, days, cost, index + 1, dp);
        int i;
        for(i = index; i<n && days[i] < days[index] + 7; i++);
        int optional2 = cost[1] + solve(n, days, cost, i, dp);

        for(i = index; i<n && days[i] < days[index] + 30; i++);
        int optional3 = cost[2] + solve(n, days, cost, i, dp);

        return dp[index] = min({optional1, optional2, optional3});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1, -1);
        return solve(n, days, costs, 0, dp);
    }
};