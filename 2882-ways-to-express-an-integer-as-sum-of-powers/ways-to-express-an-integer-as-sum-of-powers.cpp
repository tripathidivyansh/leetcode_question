#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int MOD = 1e9 + 7;
   
    int intPow(int base, int exp) {
        int result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    int Solve(int n, int num, int x, vector<vector<int>>& dp) {
        if (n == 0) return 1;   
        if (n < 0) return 0;  

        if (dp[n][num] != -1) return dp[n][num];

        int currPower = intPow(num, x);
        if (currPower > n) return dp[n][num] = 0;

        long long take = Solve(n - currPower, num + 1, x, dp);
        long long nottake = Solve(n, num + 1, x, dp);

        return dp[n][num] = (take + nottake) % MOD;
    }

    int numberOfWays(int n, int x) {
        int maxBase = pow(n, 1.0 / x) + 1; 
        vector<vector<int>> dp(n + 1, vector<int>(maxBase + 2, -1));
        return Solve(n, 1, x, dp);
    }
};

