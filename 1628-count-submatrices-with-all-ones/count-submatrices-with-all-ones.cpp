class Solution {
public:
    int Solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size();
        int m = mat[0].size();

        if (i >= n || j >= m) return 0; 
        if (dp[i][j] != -1) return dp[i][j];

       
        int width = INT_MAX, count = 0;
        for (int row = i; row < n; row++) {
            if (mat[row][j] == 0) break;
            
           
            int colCount = 0;
            for (int col = j; col < m && mat[row][col] == 1; col++) {
                colCount++;
            }

            width = min(width, colCount);
            count += width; 
        }

        return dp[i][j] = count;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;

    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    ans += Solve(i, j, mat, dp);
                }
            }
        }
        return ans;
    }
};









