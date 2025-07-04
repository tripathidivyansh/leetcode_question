class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid, int steps, int& count, int& totalStep, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1 || visited[i][j]) {
            return false;
        }
        if (grid[i][j] == 2) {
            if (steps == totalStep) {
                count++;
            }
            return false;
        }


        visited[i][j] = true;
        solve(i + 1, j, grid, steps + 1, count, totalStep, visited);
        solve(i - 1, j, grid, steps + 1, count, totalStep, visited);
        solve(i, j + 1, grid, steps + 1, count, totalStep, visited);
        solve(i, j - 1, grid, steps + 1, count, totalStep, visited);

        visited[i][j] = false;

        return false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0, totalStep = 0;

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    totalStep++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    solve(i, j, grid, 1, count, totalStep, visited);
                }
            }
        }
        return count;
    }
};