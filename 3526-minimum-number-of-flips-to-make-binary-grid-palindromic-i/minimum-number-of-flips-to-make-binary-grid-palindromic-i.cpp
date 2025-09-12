class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int rowFlips = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m / 2; c++) {
                if (grid[r][c] != grid[r][m - 1 - c]) {

                    rowFlips++;
                }
            }
        }
        int colFlips = 0;

        for (int c = 0; c < m; c++) {
            for (int r = 0; r < n / 2; r++) {
                if (grid[r][c] != grid[n - 1 - r][c]) {
                    colFlips++;

                }
            }
        }
        return min(rowFlips, colFlips);
    }
};



































































































































































































