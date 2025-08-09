class Solution {
public:
    double Solve(vector<vector<double>>& dp, int a, int b) {
        if (a <= 0 && b <= 0) return 0.5; 
        if (a <= 0) return 1.0; 

        if (b <= 0) return 0.0;           
        if (dp[a][b] >= 0) return dp[a][b]; 

        double res = 0.0;
        res += Solve(dp, a - 4, b);
        res += Solve(dp, a - 3, b - 1);
        res += Solve(dp, a - 2, b - 2);
        res += Solve(dp, a - 1, b - 3);
        res *= 0.25;

        return dp[a][b] = res;
    }
    double soupServings(int n) {

        if (n > 4800) return 1.0;
        int units = (n + 24) / 25;
        vector<vector<double>> dp(units + 1, vector<double>(units + 1, -1.0));
        return Solve(dp, units, units);
    }

};

