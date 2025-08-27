class Solution {
public:
    int dp[51][51][51];  
    int Solve(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || 
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9; 
        }
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int ans = 0;
        if (r1 == r2 && c1 == c2) {
            ans += grid[r1][c1]; 
        } else {
            ans += grid[r1][c1] + grid[r2][c2];
        }
        int dd = Solve(r1 + 1, c1, r2 + 1, grid); 
        int dr = Solve(r1 + 1, c1, r2, grid);      
        int rr = Solve(r1, c1 + 1, r2, grid);      
        int rd = Solve(r1, c1 + 1, r2 + 1, grid);  

        ans += max({dd, dr, rr, rd});

        return dp[r1][c1][r2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(0, Solve(0, 0, 0, grid));
    }
};
















